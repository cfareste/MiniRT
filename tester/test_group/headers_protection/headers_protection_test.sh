#!/bin/bash

print_headers_protection_result(){
	printf $DELETE_LINE"$1: "

	if [ $2 -ne 0 ]
	then
		printf $RED_BOLD"$WRONG_ICON\n"$RED"%s"$DEF_COLOR "$3"
		exit_status=1
	else
		printf $GREEN_BOLD$CORRECT_ICON$DEF_COLOR"\n"
		exit_status=0
	fi

	return $exit_status
}

execute_headers_protection_test(){
	local total_headers=$(find src -type f -name *.h | wc -l)
	local headers_with_prot=$(grep -rEl "#pragma once|#ifndef" --include="*.h" src | wc -l)

	if [ $total_headers -ne $headers_with_prot ]
	then
		(printf $RED"Headers not protected:$DEF_COLOR\n") > $temp_file
		(printf "$RED" && grep -rEL "#pragma once|#ifndef" --include="*.h" src && printf "$DEF_COLOR") >> $temp_file
		return 1
	fi
	return 0
}

test_headers_protection(){
	local test_title=$CYAN"Checking "$WHITE_BOLD"headers protection"
	local temp_file=$(mktemp)

	execute_headers_protection_test &
	local norme_pid=$!
	print_status $norme_pid "$test_title"
	wait $norme_pid
	local norme_exit_status=$?

	local norme_output=$(cat $temp_file)
	rm -rf $temp_file

	print_headers_protection_result "$test_title" $norme_exit_status "$norme_output"
	local test_status=$?

	return $test_status
}
