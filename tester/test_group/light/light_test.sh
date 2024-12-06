#! /bin/bash

test_light(){
	local test_group_result=0

	execute_test_group 'set_scene_defaults' $LIGHT_UC
	test_group_result=$?
	return $test_group_result
}
