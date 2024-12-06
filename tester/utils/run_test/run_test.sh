#! /bin/bash

start_lazy_kill(){
	sleep 0.05
	pkill -2 $PROGRAM
}

run_program(){
	./"$PROGRAM" $TEST_SCENE 2>&1
}

run_test(){
	local output
	local exit_status
	start_lazy_kill &
	output=$(run_program)
	exit_status=$?
	echo "$output"
	return $exit_status
}
