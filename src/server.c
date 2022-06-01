#include "server.h"
#include "encrypt.h"
#include "questions.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void wait_for_connection() {}

void run_shell_command(const char *command, int length,
                       char out_buf[static length]) {
  FILE *read_pipe = popen(command, "r");
  int n = fread(out_buf, 1, length, read_pipe);
  out_buf[n - 1] = '\0';
}


int main(void) {
  wait_for_connection();
  for (int i = 0; i < questions_count; i++) {
    Question *question = &questions[i];
    while (true) {
      char buf[100];
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
  printf("TERMINASTE!\n");
  return 0;
}
