#include "questions.h"
#include "encrypt.h"
#include "valgrind.h"
#include <math.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

char *retry_text = ENCRYPTED("ENTER para reintentar.");

double uniform_random() { return (double)rand() / RAND_MAX; }

double normal_random() {
  double U = uniform_random();
  double V = uniform_random();
  double n = sqrt(-2 * log(U)) * cos(2 * M_PI * V);
  return n;
}

void normalQuestion() {
  for (int i = 0; i < 1000; i++) {
    double r = normal_random();
    printf("%.6f ", r);
  }
}

void quine() {
  char buf[128];
  decrypt(buf, ENCRYPTED("gcc quine.c -o quine"));
  int ret = system(buf);
  if (ret != 0) {
    decrypt(buf, retry_text);
    printf("\n%s\n", buf);
    return;
  }
  decrypt(buf, ENCRYPTED("Genial!, ya lograron meter un programa en quine.c, "
                         "veamos si hace lo que corresponde."));
  puts(buf);
  decrypt(buf, ENCRYPTED("./quine | diff - quine.c"));
  ret = system(buf);
  if (ret != 0) {
    decrypt(buf, ENCRYPTED("diff encontrĂ³ diferencias."));
    printf("\n%s\n", buf);
    decrypt(buf, retry_text);
    puts(buf);
    return;
  }
  decrypt(buf, ENCRYPTED("La respuesta es chin_chu_lan_cha"));
  puts(buf);
}

void bad_write() {
  char buf[128];
  decrypt(buf, ENCRYPTED("La respuesta es fk3wfLCm3QvS\n"));
  int w = write(13, buf, strlen(buf));
  if (w == -1)
    perror("write");
  return;
}

void gdbme() {
  char buf[256];
  int pid = getpid();
  if (pid != 0x12345678) {
    decrypt(buf, retry_text);
    puts(buf);
    return;
  }
  decrypt(buf, ENCRYPTED("La respuesta es gdb_rules"));
  puts(buf);
  return;
}

char too_easy = 1;

void kill_gdb() {
  char buf[128];
  char tracer[128];

  decrypt(tracer, ENCRYPTED("grep Tracer /proc/%d/status | cut -f 2"));

  int pid = getpid();
  sprintf(buf, tracer, pid);
  FILE *out = popen(buf, "r");
  if (out != 0) {
    fgets(buf, sizeof(buf), out);
    long int gdb_pid = strtol(buf, 0, 10);
    if (gdb_pid != 0) {
      kill(gdb_pid, 9);
    }
  }
}

void filter() {
  char buf[256];
  kill_gdb();
  decrypt(buf, ENCRYPTED("La respuesta es K5n2UFfpFMUN\n"));
  time_t seed = time(NULL);
  srand(seed);
  int i = 0;
  while (true) {
    while (rand() % 100 < 15 && buf[i] != '\0') {
      fputc(buf[i++], stdout);
    }
    if (buf[i] == '\0') {
      return;
    }
    int r = rand();
    fputc((char)r - (char)(r / 95) * 95 + ' ', stderr);
  }
}

void question8() {
  char buf[128];

  kill_gdb();
  puts("\x1b[30;40m");
  decrypt(buf, ENCRYPTED("La respuesta es BUmyYq5XxXGt"));
  puts(buf);
  puts("\x1b[0m");
}

Question questions[] = {
    {
        .encrypted_hint = ENCRYPTED(
            "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer "
            "acertijo.\nEn este TP deberĂ¡n finalizar el juego que ya "
            "comenzaron resolviendo los desafĂ­os de cada nivel.\n AdemĂ¡s "
            "tendrĂ¡n que investigar otras preguntas para responder durante la "
            "defensa.\nEl desafĂ­o final consiste en crear un programa que se "
            "comporte igual que yo, es decir, que provea los mismos desafĂ­os y "
            "que sea necesario hacer lo mismo para resolverlos. No basta con "
            "esperar la respuesta.\nAdemĂ¡s, deberĂ¡n implementar otro programa "
            "para comunicarse conmigo.\nDeberĂ¡n estar atentos a los easter "
            "eggs.\nPara verificar que sus respuestas tienen el formato "
            "correcto respondan a este desafĂ­o con la palabra 'entendido\\n'"),
        .encrypted_extra_question =
            ENCRYPTED("Â¿CĂ³mo descubrieron el protocolo, la direcciĂ³n y el "
                      "puerto para conectarse?"),
        .md5_answer = MD5SUM("entendido"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED("The Wire S1E5\n5295 888 6288"),
        .encrypted_extra_question =
            ENCRYPTED("Â¿QuĂ© diferencias hay entre TCP y UDP y en quĂ© casos "
                      "conviene usar cada uno?"),
        .md5_answer = MD5SUM("itba"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED("https://ibb.co/tc0Hb6w"),
        .encrypted_extra_question =
            ENCRYPTED("Â¿El puerto que usaron para conectarse al server es el "
                      "mismo que usan para mandar las respuestas? Â¿Por quĂ©?"),
        .md5_answer = MD5SUM("M4GFKZ289aku"),
        .on_start = __L,
    },
    {
        .encrypted_hint = ENCRYPTED("EBADF...\n\n"),
        .encrypted_extra_question = ENCRYPTED(
            "Â¿QuĂ© Ăºtil abstracciĂ³n es utilizada para comunicarse con sockets? "
            "Â¿se puede utilizar read(2) y write(2) para operar?"),
        .md5_answer = MD5SUM("fk3wfLCm3QvS"),
        .on_start = bad_write,
    },
    {
        .encrypted_hint = ENCRYPTED("respuesta = strings:222"),
        .encrypted_extra_question =
            ENCRYPTED("Â¿CĂ³mo garantiza TCP que los paquetes llegan en orden y "
                      "no se pierden?"),
        .md5_answer = MD5SUM("too_easy"),
        .on_start = NULL,
    },
    {
        .encrypted_hint =
            ENCRYPTED(".data .bss .comment ?"),
        .encrypted_extra_question =
            ENCRYPTED("Un servidor suele crear un nuevo proceso o thread para "
                      "atender las conexiones entrantes. Â¿QuĂ© conviene mĂ¡s?"),
        .md5_answer = MD5SUM(".RUN_ME"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED("Filter error\n\n"),
        .encrypted_extra_question =
            ENCRYPTED("Â¿CĂ³mo se puede implementar un servidor que atienda "
                      "muchas conexiones sin usar procesos ni threads?"),
        .md5_answer = MD5SUM("K5n2UFfpFMUN"),
        .on_start = filter,
    },
    {
        .encrypted_hint = ENCRYPTED("Â¿?\n\n"),
        .encrypted_extra_question =
            ENCRYPTED("Â¿QuĂ© aplicaciones se pueden utilizar para ver el "
                      "trĂ¡fico por la red?"),
        .md5_answer = MD5SUM("BUmyYq5XxXGt"),
        .on_start = question8,
    },
    {
        .encrypted_hint = ENCRYPTED("Latexme\n\nSi\n\\mathrm{d}y = "
                                    "u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}"
                                    "\\frac{u'}{u})\nentonces\ny = "),
        .encrypted_extra_question =
            ENCRYPTED("sockets es un mecanismo de IPC. Â¿QuĂ© es mĂ¡s eficiente "
                      "entre sockets y pipes?"),
        .md5_answer = MD5SUM("u^v"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED(""),
        .encrypted_extra_question =
            ENCRYPTED("Â¿CuĂ¡les son las caracterĂ­sticas del protocolo SCTP?"),
        .md5_answer = MD5SUM("chin_chu_lan_cha"),
        .on_start = quine,
    },
    {
        .encrypted_hint = ENCRYPTED("b gdbme y encontrĂ¡ el valor mĂ¡gico"),
        .encrypted_extra_question = ENCRYPTED("Â¿QuĂ© es un RFC?"),
        .md5_answer = MD5SUM("gdb_rules"),
        .on_start = gdbme,
    },
    {
        .encrypted_hint = ENCRYPTED("Me conoces\n\n"),
        .encrypted_extra_question = ENCRYPTED("Â¿Fue divertido?"),
        .md5_answer = MD5SUM("normal"),
        .on_start = normalQuestion,
    },
};

const int questions_count = sizeof(questions) / sizeof(*questions);
