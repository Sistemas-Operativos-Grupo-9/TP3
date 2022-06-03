#include "questions.h"
#include "encrypt.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void secondQuestion() { printf("THIS STRING IS SPECIFIC TO QUESTION 2!"); }

double uniform_random() {
	return (double) rand() / RAND_MAX;
}

double normal_random() {
	double U = uniform_random();
	double V = uniform_random();
	double n = sqrt(-2 * log(U)) * cos(M_PI_2 * V);
	return n;
}

void normalQuestion() {
	for (int i = 0; i < 1000; i++) {
		double r = normal_random();
		printf("%.6f ", r);
	}
}

void quine() {
	char buf[128];
    decrypt(buf, ENCRYPTED("gcc quine.c -o quine"));
    int ret = system(buf);
    if (ret != 0) {
        decrypt(buf, ENCRYPTED("ENTER para reintentar."));
        printf("\n%s\n", buf);
        return;
    }
    decrypt(buf, ENCRYPTED("Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde."));
    puts(buf);
    decrypt(buf, ENCRYPTED("./quine | diff - quine.c"));
    ret = system(buf);
    if (ret != 0) {
        decrypt(buf, ENCRYPTED("diff encontró diferencias."));
        printf("\n%s\n", buf);
        decrypt(buf, ENCRYPTED("ENTER para reintentar."));
        puts(buf);
        return;
    }
    decrypt(buf, ENCRYPTED("La respuesta es chin_chu_lan_cha"));
    puts(buf);
}

Question questions[] = {
    {
        .encrypted_hint = ENCRYPTED(
            "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer "
            "acertijo.\nEn este TP deberán finalizar el juego que ya "
            "comenzaron resolviendo los desafíos de cada nivel.\n Además "
            "tendrán que investigar otras preguntas para responder durante la "
            "defensa.\nEl desafío final consiste en crear un programa que se "
            "comporte igual que yo, es decir, que provea los mismos desafíos y "
            "que sea necesario hacer lo mismo para resolverlos. No basta con "
            "esperar la respuesta.\nAdemás, deberán implementar otro programa "
            "para comunicarse conmigo.\nDeberán estar atentos a los easter "
            "eggs.\nPara verificar que sus respuestas tienen el formato "
            "correcto respondan a este desafío con la palabra 'entendido'"),
        .encrypted_extra_question =
            ENCRYPTED("¿Cómo descubrieron el protocolo, la dirección y el "
                      "puerto para conectarse?"),
        .md5_answer = MD5SUM("entendido"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED("The Wire S1E5\n5295 888 6288"),
        .encrypted_extra_question =
            ENCRYPTED("¿Qué diferencias hay entre TCP y UDP y en qué casos "
                      "conviene usar cada uno?"),
        .md5_answer = MD5SUM("itba"),
        .on_start = secondQuestion,
    },
    {
        .encrypted_hint = ENCRYPTED("https://ibb.co/tc0Hb6w"),
        .encrypted_extra_question =
            ENCRYPTED("¿El puerto que usaron para conectarse al server es el "
                      "mismo que usan para mandar las respuestas? ¿Por qué?"),
        .md5_answer = MD5SUM("M4GFKZ289aku"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED("EBADF...\n\nwrite: Bad file descriptor"),
        .encrypted_extra_question = ENCRYPTED(
            "¿Qué útil abstracción es utilizada para comunicarse con sockets? "
            "¿se puede utilizar read(2) y write(2) para operar?"),
        .md5_answer = MD5SUM("fk3wfLCm3QvS"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED("respuesta = strings:277"),
        .encrypted_extra_question =
            ENCRYPTED("¿Cómo garantiza TCP que los paquetes llegan en orden y "
                      "no se pierden?"),
        .md5_answer = MD5SUM("too_easy"),
        .on_start = NULL,
    },
    {
        .encrypted_hint =
            ENCRYPTED(".data .bss .comment ? .shstrtab .symtab .strtab"),
        .encrypted_extra_question =
            ENCRYPTED("Un servidor suele crear un nuevo proceso o thread para "
                      "atender las conexiones entrantes. ¿Qué conviene más?"),
        .md5_answer = MD5SUM(".RUN_ME"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED(
            "Filter error\n\ni(LDLjaH1 "
            "prt0dB_eJF+1sx@}pu=e/#stRaQBrw'@/B.>-W.f whd4Jb.$#zJ4tg "
            "pS6eKTsI45 -K5OCn}NXC3;~U{p~2>g&T&op3 {UPFJfXptgGbFM4UkcBm.UUN"),
        .encrypted_extra_question =
            ENCRYPTED("¿Cómo se puede implementar un servidor que atienda "
                      "muchas conexiones sin usar procesos ni threads?"),
        .md5_answer = MD5SUM("K5n2UFfpFMUN"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED("¿?\n\nLa respuesta es BUmyYq5XxXGt"),
        .encrypted_extra_question =
            ENCRYPTED("¿Qué aplicaciones se pueden utilizar para ver el "
                      "tráfico por la red?"),
        .md5_answer = MD5SUM("BUmyYq5XxXGt"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED("Latexme\n\nSi\n\\mathrm{d}y = "
                                    "u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}"
                                    "\\frac{u'}{u})\\nentonces\\ny = "),
        .encrypted_extra_question =
            ENCRYPTED("sockets es un mecanismo de IPC. ¿Qué es más eficiente "
                      "entre sockets y pipes?"),
        .md5_answer = MD5SUM("u^v"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED(""),
        .encrypted_extra_question =
            ENCRYPTED("¿Cuáles son las características del protocolo SCTP?"),
        .md5_answer = MD5SUM("chin_chu_lan_cha"),
        .on_start = quine,
    },
    {
        .encrypted_hint = ENCRYPTED("b gdbme y encontrá el valor mágico"),
        .encrypted_extra_question = ENCRYPTED("¿Qué es un RFC?"),
        .md5_answer = MD5SUM("gdb_rules"),
        .on_start = NULL,
    },
    {
        .encrypted_hint = ENCRYPTED("Me conoces\n\n"),
        .encrypted_extra_question = ENCRYPTED("¿Fue divertido?"),
        .md5_answer = MD5SUM("normal"),
        .on_start = normalQuestion,
    },
};

const int questions_count = sizeof(questions) / sizeof(*questions);
