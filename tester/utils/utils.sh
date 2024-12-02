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

insert_element_in_scene(){
	echo $1 >> $TEST_SCENE
}

start_lazy_kill(){
	sleep 0.02
	pkill -2 $PROGRAM
}

run_program(){
	./"$PROGRAM" $TEST_SCENE 2>&1
}

run_test(){
	local output
	local exit_status
	start_lazy_kill &
	output=$(run_program)
	exit_status=$?
	echo "$output"
	return $exit_status
}

trim_string(){
	sed -rE $'s/^[\t ]*|[\t ]*$//g'
}
