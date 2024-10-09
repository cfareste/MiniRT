#include "miniRT.h"
#include "libft.h"

void throw_error(char *msg)
{
	ft_printff(STDERR_FILENO, "Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void throw_sys_error(char *msg)
{
	ft_printff(STDERR_FILENO, "%s: %s: ", PROGRAM_NAME, msg);
	perror("");
	exit(EXIT_FAILURE);
}
