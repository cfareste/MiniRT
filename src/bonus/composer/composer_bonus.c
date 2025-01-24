/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:07:11 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composer_bonus.h"
#include "utils/utils_bonus.h"
#include "composition/composition_bonus.h"

#include "libft.h"

void	compose(t_composer *composer, int create_new_file)
{
	t_composition	*composition;

	if (composer->thread)
		pthread_join(composer->thread, NULL);
	composer->thread = 0;
	composer_set_alive(composer, 1);
	composition = ft_calloc(1, sizeof(t_composition));
	if (!composition)
		throw_sys_error("allocating composition");
	composition->composer = composer;
	composition->create_new_file = create_new_file;
	if (composer_is_alive(composer) && pthread_create(&composer->thread, NULL,
			(void *(*)(void *)) composition_routine, composition) == -1)
		throw_sys_error("creating compose thread");
}

void	init_composer(t_composer *composer, t_render *render, t_jobs *jobs,
			char **filename_ref)
{
	pthread_mutex_init(&composer->alive_mutex, NULL);
	composer->render = render;
	composer->jobs = jobs;
	composer->filename_ref = filename_ref;
}

int	composer_is_alive(t_composer *composer)
{
	int	alive;

	pthread_mutex_lock(&composer->alive_mutex);
	alive = composer->alive;
	pthread_mutex_unlock(&composer->alive_mutex);
	return (alive);
}

void	composer_set_alive(t_composer *composer, int alive)
{
	pthread_mutex_lock(&composer->alive_mutex);
	composer->alive = alive;
	pthread_mutex_unlock(&composer->alive_mutex);
}

void	destroy_composer(t_composer *composer)
{
	composer_set_alive(composer, 0);
	if (composer->thread)
		pthread_join(composer->thread, NULL);
	composer->thread = 0;
}
