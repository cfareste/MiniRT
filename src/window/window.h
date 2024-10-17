#ifndef WINDOW_H
# define WINDOW_H
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1422
# endif
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 800
# endif

# include "MLX42.h"
# include "scene/scene.h"

typedef struct s_window_size
{
	int			width;
	int			height;
}	t_window_size;

typedef struct s_window
{
	t_window_size	size;
	mlx_image_t		*image;
	mlx_t			*mlx;
	t_scene			scene;
}	t_window;

void	start_window(t_window *window);

#endif