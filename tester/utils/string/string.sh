#! /bin/bash

trim_string(){
	sed -rE $'s/^[\t ]*|[\t ]*$//g'
}

split_string_by_commas(){
	sed -rE $'s/ /, /g'
}

remove_repeated_spaces(){
	sed -rE $'s/[\t ]{1,}/ /g'
}

parse_test_result(){
	echo "$1" | trim_string | split_string_by_commas
}