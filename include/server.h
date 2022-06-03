#pragma once

#define SOCKET_PORT 8080

// Waits for a tcp connection on port 8080 and binds stdin and stdout to the connection. Aborts if any error.
void wait_for_connection();

// Runs a command in shell
void run_shell_command(const char *command, int length, char out_buf[static length]);
