/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:06:53 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/07 15:54:14 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "render/render_bonus.h"
#include <pthread.h>

typedef struct s_composer
{
	pthread_t		thread;
	int				alive;
	pthread_mutex_t	alive_mutex;
	t_render		*render;
	t_jobs			*jobs;
	t_loader		*loader;
}	t_composer;

void	init_composer(t_composer *composer, t_render *render,
			t_jobs *jobs, t_loader *loader);

void	compose(t_composer *composer);

int		composer_is_alive(t_composer *composer);

void	composer_set_alive(t_composer *composer, int alive);

void	destroy_composer(t_composer *composer);