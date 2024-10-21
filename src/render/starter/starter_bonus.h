#ifndef STARTER_BONUS_H
# define STARTER_BONUS_H

# include <pthread.h>
# include "render/loader/loader.h"

typedef struct s_render
{
	pthread_t		render;
	t_loader		loader;
	int				finished;
	pthread_mutex_t	render_mutex;
}	t_render;

typedef struct s_window	t_window;

void	start_render(t_window *window);

void	stop_render(t_render *render);

#endif