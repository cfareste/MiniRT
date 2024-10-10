#ifndef UTILS_H
# define UTILS_H

int		correct_file_extension(char *filename, char *extension);

void	throw_error(char *msg);

void	throw_sys_error(char *msg);

void	jump_spaces(char **str);

#endif