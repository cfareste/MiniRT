#! /bin/bash

test_render_settings(){
	local test_group_result=0

	execute_test_group 'set_scene_defaults' $RENDER_SETTINGS_UC
	test_group_result=$?
	return $test_group_result
}
