#include "server.h"
#include "encrypt.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void wait_for_connection() {
}

void run_shell_command(const char *command, int length, char out_buf[static length]) {
	FILE *read_pipe = popen(command, "r");
	int n = fread(out_buf, 1, length, read_pipe);
	out_buf[n - 1] = '\0';
}

static char *encrypted_md5_command = ENCRYPTED("echo -n %50s | md5sum | cut -f1 -d' '");

typedef char MD5[33];

void md5sum(const char *str, MD5 out) {
	static char buf[100];
	decrypt(buf, encrypted_md5_command);
	static char command[100];
	sprintf(command, buf, str);
	printf("%s\n", command);
	run_shell_command(command, sizeof(MD5), out);
}

struct Question {
	char *encrypted_hint;
	char *encrypted_extra_question;
	MD5 md5_answer;
	void (*on_start)();
} questions[] = {
	{
		.encrypted_hint = ENCRYPTED("Test Hint"),
		.encrypted_extra_question = ENCRYPTED("Test Extra"),
		.md5_answer = MD5SUM("answer"),
		.on_start = NULL,
	}
};

typedef struct Question Question;
const int questions_count = sizeof(questions) / sizeof(*questions);


int main(void) {
	wait_for_connection();
	for (int i = 0; i < questions_count; i++) {
		Question *question = &questions[i];
		while (true) {
			char buf[100];
			printf("\n---- HINT ----\n");
			decrypt(buf, question->encrypted_hint);
			printf("%s\n", buf);

			if (question->on_start != NULL)
				question->on_start();

			printf("\n---- EXTRA ----\n");
			decrypt(buf, question->encrypted_extra_question);
			printf("%s\n", buf);

			char *line = NULL;
			size_t n = 0;
			int length = getline(&line, &n, stdin);

			if (length == -1) {
				return 1;
			}
			line[length - 1] = 0;


			MD5 answered_md5;
			md5sum(line, answered_md5);

			printf("%s\n", answered_md5);
			printf("%s\n", question->md5_answer);
			if (strcmp(answered_md5, question->md5_answer) == 0) {
				printf("CORRECTO!");
				break;
			}
			printf("INCORRECTO!");
			sleep(1);
		}
	}
	printf("TERMINASTE!");
	return 0;
}
