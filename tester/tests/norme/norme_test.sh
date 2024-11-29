#! /bin/bash

test_norm(){
	norme_status=-1

	norme_test=$(cd .. && norminette $SRC | grep -v "OK!")

	while [ norme_status != -1 ]
	do
		printf "\033[2K\r"$CYAN"Executing "$WHITE_BOLD"norminette: "
	
		i=0
		while [ $i -lt 3 ]
		do
			printf "."
			sleep 0.3
			((i++))
		done
	done

	if [ $? -eq 0 ]
	then
		printf "\n"$RED"%s\n" "$norme_test";
		exit_status=1
	else	
		printf "$GREEN✓$DEF_COLOR\n";
		exit_status=0
	fi

	return $exit_status
}
