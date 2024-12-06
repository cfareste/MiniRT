#! /bin/bash

test_misc(){
	local test_group_result=0

	execute_test_group 'set_scene_defaults' $MISC_UC
	test_group_result=$?
	return $test_group_result
}
