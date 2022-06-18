#pragma once

void decrypt(char *dst, char *src);

#define ENCRYPTED(str) str
#define MD5SUM(str) 0

// Runs a command in shell
void run_shell_command(const char *command, int length, char out_buf[static length]);

typedef char MD5[33];

void md5sum(const char *str, MD5 out);
