#! /bin/bash

print_norme_result(){
	printf $DELETE_LINE"$1: "

	if [ $2 -eq 0 ]
	then
		printf "❌\n"$RED"%s\n"$DEF_COLOR "$3"
		exit_status=1
	else
		printf "✅"$DEF_COLOR"\n"
		exit_status=0
	fi

	return $exit_status
}

test_norme(){
	local test_title=$CYAN"Executing "$WHITE_BOLD"norminette"
	local temp_file=$(mktemp)

	(cd .. && norminette $SRC | grep -v "OK!" > $temp_file) &
	local norme_pid=$!
	print_status $norme_pid "$test_title"
	wait $norme_pid
	local norme_exit_status=$?

	local norme_output=$(cat $temp_file)
	rm -rf $temp_file

	print_norme_result "$test_title" $norme_exit_status "$norme_output"
	local test_status=$?

	return $test_status
}
