#! /bin/bash

print_ellipsis(){
	i=0

	while [ $i -lt 3 ]
	do
		printf "."
		sleep 0.3
		((i++))
	done
}

print_status(){
	while kill -0 $1 2>/dev/null
	do
		printf $DELETE_LINE"$2: "
		print_ellipsis
	done
}

set_default_camera(){
	echo $DEFAULT_CAMERA >> $TEST_SCENE
}

set_default_ambiental(){
	echo $DEFAULT_AMBIENTAL >> $TEST_SCENE
}

set_scene_defaults(){
	set_default_camera
	set_default_ambiental
}

reset_scene(){
	> $TEST_SCENE
}
