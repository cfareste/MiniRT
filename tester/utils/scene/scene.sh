create_test_scene(){
	(cd .. && > $TEST_SCENE)
}

remove_test_scene(){
	(cd .. && rm -rf $TEST_SCENE)
}

set_default_camera(){
	echo $DEFAULT_CAMERA >> $TEST_SCENE
}

set_default_ambiental(){
	echo $DEFAULT_AMBIENTAL >> $TEST_SCENE
}

set_default_figure(){
	echo -n "$DEFAULT_FIGURE		" >> $TEST_SCENE
}

set_scene_defaults(){
	set_default_camera
	set_default_ambiental
}

set_scene_defaults_with_figure(){
	set_scene_defaults
	set_default_figure
}

reset_scene(){
	> $TEST_SCENE
}

insert_element_in_scene(){
	echo $1 >> $TEST_SCENE
}
