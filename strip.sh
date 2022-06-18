#!/bin/bash

keep_symbols() {
	for symbol in $*; do
		printf -- "--keep-symbol=$symbol "
	done
}

strip -o $2 $(keep_symbols gdbme too_easy V_E A_S L__ G_G R_E I_N N_I D_A __L) $1

