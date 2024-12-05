#! /bin/bash

test_camera(){
	local test_group_result=0

	execute_test_group 'set_default_ambiental' $CAMERA_UC
	test_group_result=$?
	return $test_group_result
}
