/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:07:11 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/07 16:08:56 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composer.h"
#include "utils/utils_bonus.h"
#include "composition/composition.h"

#include "libft.h"

void	compose(t_composer *composer)
{
	t_composition	*composition;

	pthread_join(composer->thread, NULL);
	composer_set_alive(composer, 1);
	composition = ft_calloc(1, sizeof(t_composition));
	if (!composition)
		throw_sys_error("allocating composition");
	composition->composer = composer;
	if (composer_is_alive(composer) && pthread_create(&composer->thread, NULL,
			(void *(*)(void *)) composition_routine, composition) == -1)
		throw_sys_error("creating compose thread");
}

void	init_composer(t_composer *composer, t_render *render,
			t_jobs *jobs, t_loader *loader)
{
	pthread_mutex_init(&composer->alive_mutex, NULL);
	composer->render = render;
	composer->jobs = jobs;
	composer->loader = loader;
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
	pthread_join(composer->thread, NULL);
}
