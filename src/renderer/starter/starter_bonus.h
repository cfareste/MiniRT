#ifndef STARTER_BONUS
# define STARTER_BONUS

# include <pthread.h>

typedef struct s_renderer
{
	pthread_t		render;
	pthread_t		loader;
	int				finished;
	pthread_mutex_t	render_mutex;
}	t_renderer;

typedef struct s_window t_window;

void	start_renderer(t_window *window);

#endif