#! /bin/bash

reset_scene_settings_test(){
	reset_scene
	set_scene_defaults
	IFS=$'\n'
}

check_test_result(){
	local expected_exit_code=1

	if [ "$2" = "SUCCESS" ]
	then
		expected_exit_code=130
	fi

	if [ $expected_exit_code -ne $3 ] || ([ "$4" != "$5" ] && [ ! -z "$5" ])
	then
		IFS=$'\n'
		local parsed_actual="(No error returned)"
		if [ ! -z "$5" ]
		then
			splitted_actual=($5)
			parsed_actual=${splitted_actual[1]}
		fi
		printf "$RED_BOLD$WRONG_ICON$DEF_COLOR\n"
		printf $WHITE_BOLD"Testing: $PINK\"$1\"\n"$DEF_COLOR
		printf $WHITE_BOLD"Expected: $CYAN$4$DEF_COLOR\n"
		printf $WHITE_BOLD"Actual: $RED${parsed_actual}$DEF_COLOR\n\n"
		return 1
	else
		printf "$GREEN_BOLD$CORRECT_ICON$DEF_COLOR\n"
	fi

	return 0
}

test_scene_settings(){
	local test_id=1
	local output
	local test_status
	local global_result=0
	reset_scene_settings_test

	for line in $(cat < $SCENE_SETTINGS_UC)
	do
		IFS=';'
		local tokens=""
		local raw_tokens=($line)
		local expected_output="(No error expected)"

		printf "Test $PINK_BOLD$test_id$DEF_COLOR: "

		tokens[0]=${raw_tokens[0]}
		for ((i = 1; i < ${#raw_tokens[@]}; i++))
		do
			tokens[$i]=$(echo "${raw_tokens[$i]}" | trim_string)
		done

		insert_element_in_scene "${tokens[0]}"
		output=$(run_test)
		test_status=$?
		if [ ${#raw_tokens[@]} -eq 3 ]
		then
			expected_output="$TEST_SCENE -> ${tokens[2]}"
		fi
		check_test_result "${tokens[0]}" "${tokens[1]}" $test_status "$expected_output" "$output"
		local test_result=$?
		if [ $test_result -ne 0 ]
		then
			global_result=1
		fi
		((test_id++))
		reset_scene_settings_test
	done

	IFS="$OLDIFS"
	return $global_result
}
