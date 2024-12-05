/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:40 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/05 22:34:54 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_helper_bonus.h"

int	is_render_finished(t_render *render)
{
	int	finished;

	pthread_mutex_lock(&render->mutex);
	finished = render->finished;
	pthread_mutex_unlock(&render->mutex);
	return (finished);
}

void	set_render_finish(t_render *render, int value)
{
	pthread_mutex_lock(&render->mutex);
	render->finished = value;
	pthread_mutex_unlock(&render->mutex);
}

void	render_set_resize(t_render *render, int value)
{
	pthread_mutex_lock(&render->resize_mutex);
	render->resize = value;
	pthread_mutex_unlock(&render->resize_mutex);
}

int	render_get_resize(t_render *render)
{
	int	resize;

	pthread_mutex_lock(&render->resize_mutex);
	resize = render->resize;
	pthread_mutex_unlock(&render->resize_mutex);
	return (resize);
}
