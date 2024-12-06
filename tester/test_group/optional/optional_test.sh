#! /bin/bash

test_optional(){
	local test_group_result=0

	execute_test_group 'set_scene_defaults_with_figure' $OPTIONAL_UC
	test_group_result=$?
	return $test_group_result
}
