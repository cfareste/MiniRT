#ifndef WINDOW_H
# define WINDOW_H
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1422
# endif
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 800
# endif
# define ICON_PATH "assets/images/icon.png"

# include "MLX42.h"
# include "scene/scene.h"
# include "render/starter/starter_bonus.h"

typedef struct s_window_size
{
	unsigned int	width;
	unsigned int	height;
}	t_window_size;

typedef struct s_resize
{
	t_window_size	size;
	double			last_resize;
}	t_resize;

typedef struct s_window
{
	t_window_size	size;
	mlx_image_t		*image;
	pthread_mutex_t	image_mutex;
	mlx_texture_t	*icon;
	mlx_t			*mlx;
	t_scene			scene;
	t_render		render;
	t_resize		resize;
}	t_window;

void	start_window(t_window *window);

#endif