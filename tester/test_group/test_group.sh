#! /bin/bash

reset_test_group(){
	reset_scene
	$1
	IFS=$'\n'
}

process_test_result(){
	local expected_exit_code=1
	local parsed_actual="(No error returned)"

	if [ "$3" = "SUCCESS" ]
	then
		expected_exit_code=0
	fi

	if [ ! -z "$6" ]
	then
		parsed_actual=$(echo $6 | tail -1)
	fi

	if [ $expected_exit_code -ne $4 ] || ([ "$5" != "$parsed_actual" ] && [ ! -z "$6" ])
	then
		IFS=$'\n'
		local parsed_test_title=$(echo "$2" | remove_repeated_spaces)
		if has_been_signaled $4
		then
			parsed_actual=$(get_signal_name $4)
		fi
		printf $BLUE"Test "$YELLOW$1$WHITE$BLUE":\n"
		printf $WHITE" - Testing: $PINK\"$parsed_test_title\"\n"$DEF_COLOR
		printf $WHITE" - Expected: $CYAN$5$DEF_COLOR\n"
		printf $WHITE" - Actual: $RED${parsed_actual}$DEF_COLOR\n"
		return 1
	fi

	return 0
}

execute_test_group(){
	local test_id=1
	local output
	local test_status
	local group_result=0
	local test_results
	local failed_tests=()

	reset_test_group $1
	local test_line_num=$(wc -l < $TEST_SCENE)
	((test_line_num++))
	for line in $(cat < "$2")
	do
		IFS=';'
		local tokens=""
		local raw_tokens=($line)
		local expected_output="(No error expected)"

		for ((i = 0; i < ${#raw_tokens[@]}; i++))
		do
			tokens[$i]=$(echo "${raw_tokens[$i]}" | trim_string)
		done

		insert_element_in_scene "${raw_tokens[0]}"
		output=$(run_test)
		test_status=$?
		if [ ${#raw_tokens[@]} -eq 3 ]
		then
			expected_output="$TEST_SCENE:$test_line_num -> ${tokens[2]}"
		fi
		test_results=$(process_test_result $test_id "${tokens[0]}" "${tokens[1]}" $test_status "$expected_output" "$output")
		local test_exit_code=$?
		if [ $test_exit_code -ne 0 ]
		then
			printf "$RED_BOLD$WRONG_ICON$DEF_COLOR "
			failed_tests+=("$test_results\n")
			group_result=1
		else
			printf "$GREEN_BOLD$CORRECT_ICON$DEF_COLOR "
		fi
		((test_id++))
		reset_test_group $1
	done

	echo
	if [ ${#failed_tests[@]} -gt 0 ]
	then
		echo
		printf "${failed_tests[*]}"
		echo
	fi
	IFS="$OLDIFS"
	return $group_result
}
