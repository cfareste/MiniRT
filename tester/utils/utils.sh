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

trim_string(){
	sed -rE $'s/^[\t ]*|[\t ]*$//g'
}

split_string_by_commas(){
	sed -rE 's/ /, /g'
}

has_been_signaled(){
	if [ $1 -eq $EXIT_SUCCESS ] || [ $1 -eq $EXIT_FAILURE ]
	then
		return 1
	fi
	return 0
}

get_signal_name(){
	if [ $1 -eq 139 ]
	then
		echo "SIGSEGV"
	elif [ $1 -eq 134 ]
	then
		echo "SIGABORT"
	else
		echo "Unexpected error ($1)"
	fi
}
