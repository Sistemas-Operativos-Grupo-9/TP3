#include <stdio.h>

int main() {
	// TODO: Connect to localhost port 8080


	// Send these strings through socket:
	char *answers[] = {
		"entendido",
		"itba",
		"M4GFKZ289aku",
		"fk3wfLCm3QvS",
		"too_easy",
		".RUN_ME",
		"K5n2UFfpFMUN",
		"BUmyYq5XxXGt",
		"u^v",
		"chin_chu_lan_cha",
		"gdb_rules",
		"normal",
	};
	for (int i = 0; i < sizeof(answers) / sizeof(*answers); i++) {
		// TODO: Send
		printf("%s\n", answers[i]);
	}

	// TODO: Close the connection

	return 0;
}
