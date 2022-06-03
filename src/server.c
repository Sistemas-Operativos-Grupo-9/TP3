#include "server.h"
#include "encrypt.h"
#include "questions.h"
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int wait_for_connection() {
  int sock;
  /*
    AF_INET: IPv4 Internet protocols
    SOCK_STREAM: TCP
  */

  // Creo el FD del socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  /*
      struct sockaddr_in {
          sa_family_t    sin_family;  address family: AF_INET
          in_port_t      sin_port;    port in network byte order
          struct in_addr sin_addr;    internet address
      };

      struct in_addr {
          uint32_t       s_addr;      address in network byte order
      }
  */

  // Configuro la direccion del socket para escuchar en el puerto 8080
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_port = htons(SOCKET_PORT);
  address.sin_addr.s_addr = INADDR_ANY;

  if (bind(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind");
    exit(1);
  }

  // Configuro el socket para que pueda aceptar conexiones en paralelo
  // el 15 es SO_REUSEPORT pero no me lo toma 😃
  if (setsockopt(sock, SOL_SOCKET, 15, &(int){1}, sizeof(int)) < 0) {
    perror("setsockopt");
    exit(1);
  }

  // Escucho conexiones entrantes(hasta 5 en cola)
  if (listen(sock, 5) < 0) {
    perror("listen");
    exit(1);
  }

  printf("Waiting for connection...\n");
  int newSock = accept(sock, NULL, NULL);
  if (newSock == -1) {
    perror("accept");
    exit(1);
  }

  // Configuro stdin para que se conecten al socket del cliente y cierro el
  // socket del host
  dup2(newSock, 0);
  /*shutdown(sock, SHUT_RDWR);*/
  close(newSock);

  printf("Connection accepted.\n");

  return newSock;
}

void run_shell_command(const char *command, int length,
                       char out_buf[static length]) {
  FILE *read_pipe = popen(command, "r");
  if (read_pipe == NULL) {
    perror("Error");
    exit(1);
  }
  int n = fread(out_buf, 1, length, read_pipe);
  out_buf[n - 1] = '\0';
}

int main(void) {

  char buf[16384];
  int sock = wait_for_connection();
  for (int i = 0; i < questions_count; i++) {
    Question *question = &questions[i];
    while (true) {
      printf("\x1b[1;1H\x1b[2J");
      printf("\n---- HINT ----\n");
      decrypt(buf, question->encrypted_hint);
      printf("%s\n", buf);

      if (question->on_start != NULL)
        question->on_start();

      printf("\n---- EXTRA ----\n");
      decrypt(buf, question->encrypted_extra_question);
      printf("%s\n", buf);

      char *line = NULL;
      size_t n = 0;
      int length = getline(&line, &n, stdin);

      if (length == -1) {
        return 1;
      }
      line[length - 1] = 0;

      MD5 answered_md5;
      md5sum(line, answered_md5);

      if (strcmp(answered_md5, question->md5_answer) == 0) {
        printf("CORRECTO!\n");
        break;
      }
      printf("INCORRECTO!\n");
      sleep(1);
    }
  }
  puts("\x1b[1;1H\x1b[2J");
  decrypt(buf,
          ENCRYPTED(
              "Felicitaciones, finalizaron el juego. Ahora deberán implementar "
              "el servidor que se comporte como el servidor provisto!\n"));
  puts(buf);
  shutdown(sock, SHUT_RDWR);
  return 0;
}
