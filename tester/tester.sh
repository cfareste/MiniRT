#! /bin/bash

set -o nounset

. ./vars/common_vars.sh --source-only
. ./utils/utils.sh --source-only
. ./utils/run_test/run_test.sh --source-only
. ./utils/scene/scene.sh --source-only
. ./utils/signal/signal.sh --source-only
. ./utils/string/string.sh --source-only
. ./test_group/test_group.sh --source-only
. ./test_group/norme/norme_test.sh --source-only
. ./test_group/scene_settings/scene_settings_test.sh --source-only
. ./test_group/render_settings/render_settings_test.sh --source-only
. ./test_group/window_settings/window_settings_test.sh --source-only
. ./test_group/ambiental/ambiental_test.sh --source-only
. ./test_group/camera/camera_test.sh --source-only
. ./test_group/light/light_test.sh --source-only
. ./test_group/figure/figure_test.sh --source-only
. ./test_group/optional/optional_test.sh --source-only
. ./test_group/misc/misc_test.sh --source-only

print_header(){
	printf "$HEADER"
	echo
}

execute_tests(){
	local tests=$(ls $TEST_GROUP_DIR | grep -vE "norme|*.sh")
	local passed_tests=("")
	local failed_tests=("")
	local total_tests=$(ls $TEST_GROUP_DIR | grep -vE "*.sh" | wc -w)
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

	passed_tests=$(parse_test_result "${passed_tests[*]}")
	failed_tests=$(parse_test_result "${failed_tests[*]}")
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
