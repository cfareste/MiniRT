#! /bin/bash

test_misc(){
	local group_test_result=0

	execute_group_test 'set_scene_defaults' $MISC_UC
	group_test_result=$?
	return $group_test_result
}
