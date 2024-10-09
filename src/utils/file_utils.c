#include "libft.h"

int	correct_file_extension(char *filename, char *extension)
{
	size_t	extension_len;

	extension_len = ft_strlen(extension);
	return (ft_strnrcmp(filename, extension, extension_len) == EQUAL_STRINGS
		&& ft_strlen(filename) > extension_len);
}