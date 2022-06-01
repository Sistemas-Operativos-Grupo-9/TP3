#include "encrypt.h"
#include "server.h"
#include <stdio.h>

void decrypt(char *dst, char *src) {
  *dst = *src - 0x21;
  while (*src - 0x21 != 0) {
    src++;
    dst++;
    *dst = *src - 0x21;
  }
}


static char *encrypted_md5_command = ENCRYPTED("echo -n %50s | md5sum | cut -f1 -d' '");

void md5sum(const char *str, MD5 out) {
	static char buf[100];
	decrypt(buf, encrypted_md5_command);
	static char command[100];
	sprintf(command, buf, str);
	run_shell_command(command, sizeof(MD5), out);
}

