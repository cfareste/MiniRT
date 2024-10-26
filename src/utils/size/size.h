#pragma once

typedef struct s_window_size
{
	unsigned int	width;
	unsigned int	height;
}	t_size;

t_size	new_size(int height, int width);
