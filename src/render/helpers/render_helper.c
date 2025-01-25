/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:40 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:53:03 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_helper.h"

int	is_render_finished(t_render *render)
{
	int	finished;

	pthread_mutex_lock(&render->mutex);
	finished = render->finished;
	pthread_mutex_unlock(&render->mutex);
	return (finished);
}

int	is_render_alive(t_render *render)
{
	int	alive;

	pthread_mutex_lock(&render->mutex);
	alive = !render->finished;
	pthread_mutex_unlock(&render->mutex);
	return (alive);
}

void	set_render_finish(t_render *render, int value)
{
	pthread_mutex_lock(&render->mutex);
	render->finished = value;
	pthread_mutex_unlock(&render->mutex);
}
