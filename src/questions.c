#include "questions.h"
#include <stddef.h>
#include <stdio.h>

void secondQuestion()
{
	printf("THIS STRING IS SPECIFIC TO QUESTION 2!");
}

Question questions[] = {
	{
		.encrypted_hint = ENCRYPTED("Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n Además tendrán que investigar otras preguntas para responder durante la defensa.\nEl desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\nAdemás, deberán implementar otro programa para comunicarse conmigo.\nDeberán estar atentos a los easter eggs.\nPara verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'"),
		.encrypted_extra_question = ENCRYPTED("¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?"),
		.md5_answer = MD5SUM("entendido"),
		.on_start = NULL,
	},
	{
		.encrypted_hint = ENCRYPTED("The Wire S1E5\n5295 888 6288"),
		.encrypted_extra_question = ENCRYPTED("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?"),
		.md5_answer = MD5SUM("itba"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED("https://ibb.co/tc0Hb6w"),
		.encrypted_extra_question = ENCRYPTED("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?"),
		.md5_answer = MD5SUM("M4GFKZ289aku"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED("EBADF...\n\nwrite: Bad file descriptor"),
		.encrypted_extra_question = ENCRYPTED("¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?"),
		.md5_answer = MD5SUM("fk3wfLCm3QvS"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED("respuesta = strings:277"),
		.encrypted_extra_question = ENCRYPTED("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?"),
		.md5_answer = MD5SUM("too_easy"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED(".data .bss .comment ? .shstrtab .symtab .strtab"),
		.encrypted_extra_question = ENCRYPTED("Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?"),
		.md5_answer = MD5SUM(".RUN_ME"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED("Filter error\n\ni(LDLjaH1 prt0dB_eJF+1sx@}pu=e/#stRaQBrw'@/B.>-W.f whd4Jb.$#zJ4tg pS6eKTsI45 -K5OCn}NXC3;~U{p~2>g&T&op3 {UPFJfXptgGbFM4UkcBm.UUN"),
		.encrypted_extra_question = ENCRYPTED("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?"),
		.md5_answer = MD5SUM("K5n2UFfpFMUN"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED("¿?\n\nLa respuesta es BUmyYq5XxXGt"),
		.encrypted_extra_question = ENCRYPTED("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?"),
		.md5_answer = MD5SUM("BUmyYq5XxXGt"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED("Latexme\n\nSi\n\mathrm{d}y = u^v{\cdot}(v'{\cdot}\ln{(u)}+v{\cdot}\frac{u'}{u})\nentonces\ny = "),
		.encrypted_extra_question = ENCRYPTED("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?"),
		.md5_answer = MD5SUM("u^v"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED("quine\n\ncc1: fatal error: quine.c: No such file or directory\ncompilation terminated.\n\nENTER para reintentar."),
		.encrypted_extra_question = ENCRYPTED("¿Cuáles son las características del protocolo SCTP?"),
		.md5_answer = MD5SUM("chin_chu_lan_cha"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED("b gdbme y encontrá el valor mágico"),
		.encrypted_extra_question = ENCRYPTED("¿Qué es un RFC?"),
		.md5_answer = MD5SUM("gdb_rules"),
		.on_start = secondQuestion,
	},
	{
		.encrypted_hint = ENCRYPTED("Me conoces\n\n-1.142108 -1.859147 0.033809 -0.636179 -0.743332 1.294521 -0.061113 1.371770 -1.817671 -0.501007 1.209172 -0.678517 0.286362 0.447999 1.069698 1.429696 -0.979721 1.002646 -0.576014 -0.539043 1.332862 0.917441 -1.729031 0.424043 -0.094657 -1.109473 -0.203919 -0.121609 -1.062523 1.366048 -0.954410 1.702097 -1.518409 -0.287924 -1.497060 -2.853305 -0.053218 -0.864142 0.526291 0.795467 0.361219 -0.441929 -1.124074 0.532148 0.086117 -0.662144 0.362543 1.219225 0.657347 0.895071 -1.127873 0.505542 -0.250547 -0.964788 1.501222 -0.727671 1.279852 0.201266 -1.033443 -0.608695 0.087480 -0.588058 0.317569 -0.276658 0.412579 -0.523589 -0.951971 -1.393487 -0.620168 2.532728 -0.368677 1.400946 0.647759 -0.283161 -0.950224 -0.702743 -1.283808 0.624061 -1.513499 0.120340 -0.094423 0.435549 1.028530 0.943797 -0.930220 0.321170 -0.282183 1.890659 0.981977 1.349989 1.054672 -0.497940 -1.064924 0.145054 0.082078 -3.062059 -0.844536 -0.068104 -0.605025 0.689856 -0.279840 -0.072175 0.435572 0.416326 -0.033831 -1.256311 -0.538834 -1.384679 2.968981 1.940783 0.392928 -0.593602 -0.253766 0.522704 -0.017478 -1.826260 1.153273 0.240125 0.808291 0.499811 -0.416264 -0.096137 -1.442758 1.299562 0.086534 -1.308141 -0.408958 0.472606 0.720542 -0.878004 -1.097038 1.095303 0.941785 0.702807 -1.526907 0.100134 -3.465455 0.314128 1.850013 -0.020157 -1.637915 -1.722883 0.869110 0.463465 0.743109 0.420930 1.027140 1.639276 2.078490 -0.147251 1.139515 -1.202284 -0.773697 -0.516443 1.301202 -1.307708 -1.424656 -2.020456 1.050981 0.909200 -0.097017 -1.887119 0.995098 -0.746097 -0.556385 -0.330636 -0.582143 1.263005 -0.004332 0.624994 0.202048 1.023550 -0.175829 1.000811 0.574372 -2.198807 0.677466 1.858195 1.414851 -0.853977 -0.935687 -0.221002 0.346603 -1.319368 0.099291 -0.916847 0.675181 0.517839 0.369283 -1.646769 -0.321548 1.515284 0.219705 -0.251825 -1.952051 -0.059247 0.349621 -0.642679 -1.425050 0.777657 0.417207 0.701204 -0.107098 1.129224 -1.187272 0.055453 -0.587154 0.476981 -0.985607 -0.009960 0.195232 0.862357 -0.099841 -0.046657 0.212923 -1.222419 0.362562 -0.595894 0.565746 1.147339 0.860152 0.665635 -1.343641 1.017152 0.425513 0.701009 0.267480 0.710227 -0.585372 -1.773398 -1.224884 1.327056 -0.241914 -0.761373 1.135771 0.647286 0.292801 0.426506 0.847803 -0.346631 -1.858720 1.129142 0.829327 0.367074 -0.080584 -0.558265 0.200585 -0.293666 1.137708 2.239937 -0.221534 0.251115 -0.051226 0.180814 0.341234 0.940494 1.357567 2.037490 1.012655 -1.681329 1.277315 -1.045872 -0.567468 -0.994307 0.802631 -1.438719 0.279176 0.465107 -0.025832 0.405973 2.065311 -0.653446 0.096688 1.079136 0.156172 -1.045671 -0.410159 -0.464524 1.519547 0.132992 0.445934 -1.074362 -0.670926 -0.447162 0.116171 1.803281 1.725300 0.235446 0.392411 1.601632 0.247764 -0.935431 -1.175394 -0.407789 1.376198 -1.066984 0.767700 -1.301246 0.893095 -2.229126 0.549009 -0.443858 1.813965 0.894979 0.623364 1.576860 -0.294216 1.058194 -1.522825 -0.634361 -0.376536 0.101898 1.922407 -0.836051 -0.378248 2.523818 -0.768021 1.388899 0.664446 -2.297936 0.443417 0.009606 0.463396 1.445196 0.733416 0.645377 -1.164075 -0.149153 -0.992978 -1.722299 -0.012436 0.086561 0.525542 0.012253 -0.033732 -0.398928 -0.056001 0.254204 1.667467 -0.077046 -1.897544 -0.512125 0.149099 -1.836288 -0.637575 -1.339693 -0.537115 -0.880866 0.504839 -0.029580 -0.783956 -0.987727 0.190793 0.962441 1.538732 0.109339 -1.117398 -0.738090 1.039985 -1.263960 0.781836 0.261689 0.352408 -1.626310 -0.134488 -0.920631 0.041557 -0.970839 -0.398312 -0.799653 0.932074 0.483428 -0.783197 1.105001 -1.170705 -0.477515 -0.815434 -1.272274 -0.780272 -0.160200 -1.837089 0.287214 -0.084824 0.088864 -1.025344 0.588165 -0.370254 0.222774 -0.383648 0.557558 -0.490461 -0.972844 1.459494 0.479285 -0.009481 -0.661862 1.307152 0.578093 0.123339 -0.183256 1.620461 0.293554 -0.613120 0.182210 0.452129 -0.360526 -0.330180 2.204473 1.510029 -0.284976 -0.891700 1.395382 0.908678 -0.343926 0.286072 1.171342 1.757582 0.397499 0.789638 -2.873814 0.191804 -1.129181 0.675887 -0.854286 -1.919565 0.407398 -0.170875 -0.570219 -0.860004 -0.218143 -0.033348 1.213371 -1.254402 0.276439 1.509762 -0.005004 -0.582422 0.454101 -0.738083 0.886993 -0.434272 0.577276 -0.361497 -0.210162 0.127243 -0.053719 1.016447 -0.227184 -0.589850 0.280135 0.967552 -2.332969 0.997135 -0.594785 0.671135 -0.761660 0.764840 1.611228 -1.499107 0.935530 1.062741 0.507313 -1.727904 -0.696364 -0.506334 1.076816 -1.411569 1.108076 0.259569 0.571071 -0.809190 1.686130 -0.482978 -0.124728 -0.471607 -0.065181 -1.313623 -1.481822 2.571436 -0.778884 -1.431738 -1.677636 -0.552236 0.078411 -0.792032 2.239108 1.181125 -0.194920 0.520624 0.470856 -0.012156 -1.326948 -0.447225 -0.129597 0.916809 0.065285 0.562842 0.314743 0.601717 1.243426 -1.099679 -0.234614 0.189559 0.305498 -0.722366 0.147159 -0.195164 -1.574804 0.642400 1.646476 0.102260 -0.582222 -0.182940 0.534669 1.252832 -0.577622 0.678599 -0.397474 0.058393 -1.326511 -0.215293 -0.247829 -1.365118 -0.177960 -0.820666 0.393899 -0.706873 0.564008 0.632116 1.457078 -2.025621 0.056626 0.956488 -2.353379 -1.709392 2.224215 -0.895734 -0.666964 0.500197 -1.472973 1.012614 -0.790093 -0.334411 -0.553683 0.601974 0.669177 1.377512 1.036599 -0.170763 0.443763 -1.719591 -0.053593 0.369485 0.168027 1.987367 -0.455819 0.168512 -2.405310 -1.057353 0.292123 0.565848 0.112754 -1.788858 0.402803 -1.500537 -0.459532 -2.889316 1.003052 -0.541115 -0.184007 1.169566 -1.130344 -0.557588 -0.122683 0.978604 -1.229746 -0.133063 0.885300 0.769907 0.438458 -0.885588 -0.827721 1.889336 -0.134959 -0.329405 0.316127 0.858720 0.296536 0.903342 -0.731715 0.270631 0.497308 0.175520 -2.079501 -0.853055 0.850778 0.171487 0.804772 0.093449 -0.467461 0.069741 1.098821 -1.576028 -1.713319 -0.370177 -0.076573 -0.534019 0.642264 0.114888 -0.413767 0.099374 1.194781 1.271490 -1.211078 1.504768 0.681235 -0.678363 -0.192021 0.953017 0.741723 -1.126088 0.238931 -2.039929 1.537346 1.169393 -1.403360 -0.813009 -1.099249 -0.319670 1.835379 -0.904520 0.279603 -1.806889 -1.964118 0.542611 1.067242 -0.847661 -1.738936 -0.551965 0.916247 -0.120014 -1.018385 1.091624 0.081720 0.344828 -1.595488 0.971815 0.097400 -0.665308 1.763775 -0.140431 -0.284628 1.847940 0.416812 -0.434691 1.654796 -1.838913 -1.490925 -0.300378 -0.957242 0.421390 0.376045 0.387195 -0.469666 1.068121 -0.529423 -0.484461 1.435457 1.150642 0.652578 0.857978 -0.425677 0.333622 0.215787 -1.140290 0.909685 -1.387153 1.240502 0.796802 0.285274 2.859944 0.207443 1.342325 0.480329 -2.132811 -0.522143 0.035560 0.246942 0.048396 -3.025919 -0.751215 -0.847979 -1.588498 0.636857 -0.669999 -1.954943 1.448513 -0.401495 2.107459 0.447578 -0.936150 0.847524 -1.819475 0.475930 0.251405 -0.750408 1.101447 -0.752237 0.925110 0.556678 -0.010269 -0.219326 0.690124 0.850781 2.166743 -1.410002 -0.474840 -0.941353 -1.059888 -0.809429 -0.808291 -1.692790 -1.088365 1.588943 0.867266 0.529023 0.725960 -0.919852 0.375648 1.649241 -0.148091 -0.194706 0.003398 0.092283 -0.952094 -0.074753 0.466466 -0.180044 -1.364593 -0.044730 -1.286091 1.049317 1.294146 -0.450290 -0.066728 1.035220 3.347668 1.938494 1.765597 0.648444 1.078061 -0.988226 0.271194 0.090206 1.299180 0.135448 -1.131202 0.362236 -0.671521 -1.652145 -2.310848 1.211795 -1.069429 -0.634251 -0.223497 0.777277 1.485090 0.433255 -0.013482 -0.785415 -1.296325 0.379847 0.280596 -0.844332 1.050937 -2.374433 -1.219384 0.931685 -1.113943 -0.724217 0.121153 0.061113 -0.479357 0.694804 0.579200 0.461712 -0.231487 0.567985 -0.172113 -0.545198 -0.632488 -0.204018 -1.926038 0.396794 -0.363179 0.344979 -1.234802 -0.445803 0.288470 -0.384181 -0.620028 1.487387 0.517829 2.313318 -0.619365 -0.585274 0.331162 -0.146640 -0.596438 0.724318 -0.463701 -1.307967 -2.502152 1.601919 1.248908 1.696859 -1.420463 -0.335350 1.685957 -0.488372 -0.554145 0.923415 -0.439765 -0.852218 -0.872547 0.851327 -0.404642 0.971583 -2.008188 -0.716525 1.297620 -0.308225 -0.807319 -1.441878 -1.374989 0.345630 -2.137998 2.437330 -1.304237 -0.831546 0.259231 0.477299 0.877815 0.232917 -1.180402 1.435543 -0.290952 0.745571 -0.451603 -0.818040 -1.915529 0.254100 -1.958670 0.766385 -1.411875 1.051704 0.753245 -0.520814 -2.689019 -1.836530 -0.215150 -1.211080 1.802716 0.291111 0.452437 0.911531 1.409547 -1.174349 -0.497168 -0.556124 0.163933 -0.496266 1.570629 0.797612 -0.111273 -0.756889 0.538580 1.839201 -1.018102 2.255874 -0.829785 -0.427030 0.912039 0.454439 -1.282494 -0.865650 -0.966982 -0.837245 0.623863 -0.079891 -1.135731 0.472830 0.493215 0.277953 1.751276 -0.362549 0.362274 -0.143613 0.266691 0.081594 -1.552150 0.314695 -1.441713 0.457068 -0.572167 1.411400 0.186729 -0.399695 0.245733 0.935906 -1.623149 1.182993 -0.877268 -0.098176 -1.792729 -1.145524 2.020205 0.535154 0.052720 -2.899171 1.586204 0.722087 1.242613 0.285700 -2.750835 0.028379 0.189851 -1.663405 -0.868185 0.239300 0.159304 1.641667 -1.608406 1.799955 0.491098 -1.172033 1.533884 -0.561647 -0.436045 1.341776 0.517494 1.779064 -0.371453 0.706434 0.842537 -0.677619 1.331484 -0.955136 0.488071 -0.473622 2.085812 -0.758918 -0.220317 -0.012607 0.902060 0.900582 -0.031609 0.540688 0.959090 -0.079830 -1.769094 -1.205886 1.373668 0.112181 -0.275255 0.321501 -1.526358 1.873792 -0.006906 -0.303882 -1.021863 -1.114020 1.264669 0.234556 -0.317781 -0.322026 -0.223672 0.200131 0.579815 0.320397 -1.777361 -0.204736 2.843814 -0.252935 0.180903 -0.103016 0.668583 0.607717 2.859815 -1.066377 1.451459 0.419254 0.387923 -1.262027 0.222855 -0.141158 -0.952090 -1.600395 -1.083823 0.182890"),
		.encrypted_extra_question = ENCRYPTED("¿Fue divertido?"),
		.md5_answer = MD5SUM("normal"),
		.on_start = secondQuestion,
	},
};

const int questions_count = sizeof(questions) / sizeof(*questions);
