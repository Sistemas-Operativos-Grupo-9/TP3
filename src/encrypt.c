#include "encrypt.h"

void decrypt(char *dst, char *src) {
  *dst = *src - 0x21;
  while (*src - 0x21 != 0) {
    src++;
    dst++;
    *dst = *src - 0x21;
  }
}

