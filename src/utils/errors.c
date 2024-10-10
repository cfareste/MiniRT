#include "miniRT.h"
#include "libft.h"
#include <string.h>
#include <errno.h>

void	throw_error(char *msg)
{
	ft_printff(STDERR_FILENO, "Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	throw_sys_error(char *msg)
{
	ft_printff(STDERR_FILENO, "%s: %s: %s", PROGRAM_NAME, msg, strerror(errno));
	exit(EXIT_FAILURE);
}
