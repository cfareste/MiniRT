#! /bin/bash

test_ambiental(){
	local test_group_result=0

	execute_test_group 'set_default_camera' $AMBIENTAL_UC
	test_group_result=$?
	return $test_group_result
}
