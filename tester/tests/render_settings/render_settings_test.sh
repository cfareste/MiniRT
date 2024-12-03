#! /bin/bash

test_render_settings(){
	local group_test_result=0

	execute_group_test 'set_scene_defaults' $RENDER_SETTINGS_UC
	group_test_result=$?
	return $group_test_result
}
