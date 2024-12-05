#! /bin/bash

test_scene_settings(){
	local test_group_result=0

	execute_test_group 'set_scene_defaults' $SCENE_SETTINGS_UC
	test_group_result=$?
	return $test_group_result
}
