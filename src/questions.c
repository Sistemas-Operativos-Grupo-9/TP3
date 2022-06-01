#include "questions.h"
#include <stddef.h>
#include <stdio.h>


void secondQuestion() {
	printf("THIS STRING IS SPECIFIC TO QUESTION 2!");
}


Question questions[] = {
	{
		.encrypted_hint = ENCRYPTED("Test Hint"),
		.encrypted_extra_question = ENCRYPTED("Test Extra"),
		.md5_answer = MD5SUM("answer"),
		.on_start = NULL,
	},
	{
		.encrypted_hint = ENCRYPTED("Test Hint 2"),
		.encrypted_extra_question = ENCRYPTED("Test Extra 2"),
		.md5_answer = MD5SUM("answer2"),
		.on_start = secondQuestion,
	},
};

const int questions_count = sizeof(questions) / sizeof(*questions);
