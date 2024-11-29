#! /bin/bash

. ./common_vars.sh --source-only
. ./tests/norme/norme_test.sh --source-only

header="Amethyst MiniRT tester"

init_tester(){
	printf "$PINK_BOLD$header$DEF_COLOR\n"

	test_norm
	norme_status=$?

	
}

init_tester
