#ifndef STARTER_BONUS_H
# define STARTER_BONUS_H

# include <pthread.h>

typedef struct s_renderer
{
	pthread_t		render;
	pthread_t		loader;
	int				finished;
	pthread_mutex_t	render_mutex;
}	t_renderer;

typedef struct s_window	t_window;

void	start_renderer(t_window *window);

void	stop_renderer(t_renderer *renderer);

#endif