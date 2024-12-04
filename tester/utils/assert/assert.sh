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

reset_group_test(){
	reset_scene
	$1
	IFS=$'\n'
}

process_test_result(){
	local expected_exit_code=1

	if [ "$3" = "SUCCESS" ]
	then
		expected_exit_code=130
	fi

	if [ $expected_exit_code -ne $4 ] || ([ "$5" != "$6" ] && [ ! -z "$6" ])
	then
		IFS=$'\n'
		local parsed_test_title=$(echo "$2" | remove_repeated_spaces)
		local parsed_actual="(No error returned)"
		if has_been_signaled $4
		then
			parsed_actual=$(get_signal_name $4)
		elif [ ! -z "$6" ]
		then
			local splitted_actual=($6)
			parsed_actual=${splitted_actual[1]}
		fi
		printf $BLUE"Test "$YELLOW$1$WHITE$BLUE":\n"
		printf $WHITE" - Testing: $PINK\"$parsed_test_title\"\n"$DEF_COLOR
		printf $WHITE" - Expected: $CYAN$5$DEF_COLOR\n"
		printf $WHITE" - Actual: $RED${parsed_actual}$DEF_COLOR\n"
		return 1
	fi

	return 0
}

execute_group_test(){
	local test_id=1
	local output
	local test_status
	local group_result=0
	local test_results
	local failed_tests=()

	reset_group_test $1
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
			expected_output="$TEST_SCENE -> ${tokens[2]}"
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
		reset_group_test $1
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
