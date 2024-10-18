#ifndef WINDOW_HELPER_H
# define WINDOW_HELPER_H

# include "MLX42.h"
# include "window/window.h"

void	window_resized(int32_t width, int32_t height, t_window *window);

int		diff_sizes(t_window_size *a, t_window_size *b);

#endif