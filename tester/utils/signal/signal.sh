#! /bin/bash

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
