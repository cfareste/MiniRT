#! /bin/bash

run_program(){
	$TESTER/$MAIN_TEST_DIR/$PROGRAM $TEST_SCENE 2>&1
}

run_test(){
	local output
	local exit_status
	output=$(run_program)
	exit_status=$?
	echo "$output"
	return $exit_status
}
