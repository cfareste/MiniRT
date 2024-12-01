#! /bin/bash

set -o nounset

. ./common_vars.sh --source-only
. ./utils.sh --source-only
. ./tests/norme/norme_test.sh --source-only

header=$PINK_BOLD"Amethyst MiniRT tester"$DEF_COLOR

init_tester(){
	printf "$header\n"

	test_norme
	norme_status=$?

	return 0
}

init_tester $@
