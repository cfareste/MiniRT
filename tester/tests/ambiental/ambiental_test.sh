#! /bin/bash

test_ambiental(){
	local group_test_result=0

	execute_group_test 'set_default_camera' $AMBIENTAL_UC
	group_test_result=$?
	return $group_test_result
}
