#! /bin/bash

test_window_settings(){
	local test_group_result=0

	execute_test_group 'set_scene_defaults' $WINDOW_SETTINGS_UC
	test_group_result=$?
	return $test_group_result
}
