#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define IP "127.0.0.1"

int main() {
  // Connect to localhost port 8080
  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return -1;
  }
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, IP, &serv_addr.sin_addr) <= 0) {
    perror("Address parsing");
    return -1;
  }

  int clientfd;
  if ((clientfd = connect(sockfd, (struct sockaddr *)&serv_addr,
                          sizeof(serv_addr))) < 0) {
    perror("Connection");
    return -1;
  }

  // Send these strings through socket:
  char *answers[] = {
      "entendido",        "itba",         "M4GFKZ289aku",
      "fk3wfLCm3QvS",     "too_easy",     ".RUN_ME",
      "K5n2UFfpFMUN",     "BUmyYq5XxXGt", "u^v",
      "chin_chu_lan_cha", "gdb_rules",    "normal",
  };
  for (int i = 0; i < sizeof(answers) / sizeof(*answers); i++) {
    printf("%s\n", answers[i]);
    // Send
	send(sockfd, answers[i], strlen(answers[i]), 0);
	send(sockfd, "\n", 1, 0);
  }

  // Close the connection
  close(clientfd);

  return 0;
}
