#pragma once

#define SOCKET_PORT 8080

// Waits for a tcp connection on port 8080 and binds stdin and stdout to the connection. Aborts if any error.
int wait_for_connection();
