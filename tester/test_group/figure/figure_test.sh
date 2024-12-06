#! /bin/bash

test_figure(){
	local test_group_result=0

	execute_test_group 'set_scene_defaults' $FIGURE_UC
	test_group_result=$?
	return $test_group_result
}
