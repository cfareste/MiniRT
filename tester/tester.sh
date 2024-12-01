#! /bin/bash

set -o nounset

. ./common_vars.sh --source-only
. ./utils.sh --source-only
. ./tests/norme/norme_test.sh --source-only
. ./tests/scene_settings/scene_settings_test.sh --source-only

header=$PINK_BOLD"Amethyst MiniRT tester"$DEF_COLOR

execute_tests(){
	local tests=$(ls tests/)
	local passed_tests=""
	local failed_tests=""
	local total_tests=$(ls tests/ | wc -w)
	local num_passed=0
	local num_failed=0

	for test in $tests
	do
		local test_name="test_"$test
		$test_name
		local test_status=$?

		if [ $test_status -eq 0 ]
		then
			passed_tests=($passed_tests $test)
			((num_passed++))
		else
			failed_tests=($failed_tests $test)
			((num_failed++))
		fi
	done

	echo
	printf $YELLOW"Summary:\n"
	printf $WHITE"Passed: "$GREEN"%s\n"$DEF_COLOR "${passed_tests[*]}"
	printf $WHITE"Failed: "$RED"%s\n"$DEF_COLOR "${failed_tests[*]}"
	printf $WHITE"Total: "$GREEN_BOLD"%d"$WHITE" | "$RED_BOLD"%d"$WHITE" | "$YELLOW"%d\n"$DEF_COLOR $num_passed $num_failed $total_tests
}

init_tester(){
	printf "$header\n"

	execute_tests
	return 0
}

init_tester $@
