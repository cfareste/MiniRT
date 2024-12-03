#! /bin/bash

test_optional(){
	local group_test_result=0

	execute_group_test 'set_scene_defaults_with_figure' $OPTIONAL_UC
	group_test_result=$?
	return $group_test_result
}
