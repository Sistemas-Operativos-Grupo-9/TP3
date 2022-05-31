#include <stdio.h>

#define ENCRYPTED(str) str

char *str1 = ENCRYPTED("Hola, este es un string");
char *str2 = ENCRYPTED("Este es otro string");
char *str3 = ENCRYPTED("No me deberias poder leer");


char *strings[] = {
    ENCRYPTED("El primer string!"),
    ENCRYPTED("El segundo string!"),
    ENCRYPTED("..."),
    ENCRYPTED("Hmm?"),
    ENCRYPTED("Jerston"),
};

void decrypt(char *dst, char *src) {
  *dst = *src - 0x21;
  while (*src - 0x21 != 0) {
    src++;
    dst++;
    *dst = *src - 0x21;
  }
}

int main() {
  char buf[100];
  decrypt(buf, strings[0]);
  printf("%s\n", buf);
  return 0;
}
