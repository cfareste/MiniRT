#ifndef MINIRT_H
# define MINIRT_H
# define PROGRAM_NAME "miniRT"
# ifndef DARWIN
#  define DARWIN 0
# endif
# ifndef LINUX
#  define LINUX 0
# endif

# include "window/window.h"

void	destroy(t_window *window);

#endif