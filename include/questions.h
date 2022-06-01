#pragma once
#include "encrypt.h"

typedef struct Question Question;

struct Question {
	char *encrypted_hint;
	char *encrypted_extra_question;
	MD5 md5_answer;
	void (*on_start)();
};

extern Question questions[];
extern const int questions_count;
