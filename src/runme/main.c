#include "encrypt.h"
#include <stdio.h>

char buf[128];
int main() {
  decrypt(buf, ENCRYPTED("Estoy muy orgulloso de que hayan logrado esto. Les "
                         "espera un premio especial."));
  puts(buf);
  return 0;
}
