/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:06:53 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:52:05 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MODIFY_EXISTING 0
#define CREATE_FILE 1

#include "render/render.h"
#include "window/jobs/jobs.h"

typedef struct s_composer
{
	pthread_t		thread;
	int				alive;
	pthread_mutex_t	alive_mutex;
	t_render		*render;
	t_jobs			*jobs;
	char			**filename_ref;
}	t_composer;

void	init_composer(t_composer *composer, t_render *render, t_jobs *jobs,
			char **filename_ref);

void	compose(t_composer *composer, int create_new_file);

int		composer_is_alive(t_composer *composer);

void	composer_set_alive(t_composer *composer, int alive);

void	destroy_composer(t_composer *composer);
