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
