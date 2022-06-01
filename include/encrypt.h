#pragma once

void decrypt(char *dst, char *src);

#define ENCRYPTED(str) str
#define MD5SUM(str) 0

typedef char MD5[33];

void md5sum(const char *str, MD5 out);
