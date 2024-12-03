#! /bin/bash

test_camera(){
	local group_test_result=0

	execute_group_test 'set_default_ambiental' $CAMERA_UC
	group_test_result=$?
	return $group_test_result
}
