#include "ft_strncmp.h"

void	jump_spaces(char **str)
{
	while (ft_strcmp(**str, ' ') == EQUAL_STRINGS)
		(*str)++;
}
