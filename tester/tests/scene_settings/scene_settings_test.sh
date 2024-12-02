#! /bin/bash

reset_scene_settings_test(){
	reset_scene
	set_scene_defaults
	IFS=$'\n'
}

test_scene_settings(){
	local group_test_result=0

	execute_group_test 'reset_scene_settings_test' $SCENE_SETTINGS_UC
	group_test_result=$?
	return $group_test_result
}
