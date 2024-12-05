#! /bin/bash

set -o nounset

. ./vars/common_vars.sh --source-only
. ./utils/utils.sh --source-only
. ./utils/assert/assert.sh --source-only
. ./utils/scene/scene.sh --source-only
. ./tests/norme/norme_test.sh --source-only
. ./tests/scene_settings/scene_settings_test.sh --source-only
. ./tests/render_settings/render_settings_test.sh --source-only
. ./tests/window_settings/window_settings_test.sh --source-only
. ./tests/ambiental/ambiental_test.sh --source-only
. ./tests/camera/camera_test.sh --source-only
. ./tests/light/light_test.sh --source-only
. ./tests/figure/figure_test.sh --source-only
. ./tests/optional/optional_test.sh --source-only
. ./tests/misc/misc_test.sh --source-only

print_header(){
	printf "$HEADER"
	echo
}

execute_tests(){
	local tests=$(ls tests/ | grep -v "norme")
	local passed_tests=("")
	local failed_tests=("")
	local total_tests=$(ls tests/ | wc -w)
	local num_passed=0
	local num_failed=0

	(cd .. && test_norme)
	if [ $? -eq 0 ]
	then
		passed_tests+=("norme")
		((num_passed++))
	else
		failed_tests+=("norme")
		((num_failed++))
	fi

	echo
	for test in $tests
	do
		local test_name="test_"$test
		printf $CYAN"Running "$WHITE_BOLD$test$CYAN": "$DEF_COLOR
		(cd .. && $test_name)
		local test_status=$?

		if [ $test_status -eq 0 ]
		then
			passed_tests+=($test)
			((num_passed++))
		else
			failed_tests+=($test)
			((num_failed++))
		fi
	done

	passed_tests=$(echo "${passed_tests[*]}" | trim_string | split_string_by_commas)
	failed_tests=$(echo "${failed_tests[*]}" | trim_string | split_string_by_commas)
	echo
	printf $YELLOW"Summary:\n"
	printf $WHITE"Passed: "$GREEN"%s\n"$DEF_COLOR "$passed_tests"
	printf $WHITE"Failed: "$RED"%s\n"$DEF_COLOR "$failed_tests"
	printf $WHITE"Total: "$GREEN_BOLD"%d"$WHITE" | "$RED_BOLD"%d"$WHITE" | "$YELLOW_BOLD"%d\n"$DEF_COLOR $num_passed $num_failed $total_tests
}

execute_make(){
	(cd .. && make > /dev/null) &
}

compile_binary(){
	local title=$CYAN"Compiling "$WHITE_BOLD$PROGRAM
	execute_make
	local update_pid=$!

	print_status $update_pid "$title"
	wait $update_pid
	printf $DELETE_LINE"$title: "$GREEN_BOLD$CORRECT_ICON$DEF_COLOR"\n"
}

init_tester(){
	print_header
	compile_binary
	create_test_scene
	execute_tests
	remove_test_scene
	return 0
}

init_tester $@