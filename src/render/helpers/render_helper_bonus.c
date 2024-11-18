/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:40 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 18:07:56 by cfidalgo         ###   ########.fr       */
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
