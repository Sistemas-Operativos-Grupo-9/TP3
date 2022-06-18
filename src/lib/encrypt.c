#include "encrypt.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>

void decrypt(char *dst, char *src) {
  *dst = *src - 0x21;
  while (*src - 0x21 != 0) {
    src++;
    dst++;
    *dst = *src - 0x21;
  }
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


static char *encrypted_md5_command = ENCRYPTED("echo -n %50s | md5sum | cut -f1 -d' '");

void md5sum(const char *str, MD5 out) {
	static char buf[100];
	decrypt(buf, encrypted_md5_command);
	static char command[100];
	sprintf(command, buf, str);
	run_shell_command(command, sizeof(MD5), out);
}

