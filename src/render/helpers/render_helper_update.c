/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:13:18 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/12 17:28:10 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_helper_bonus.h"

int	get_render_update(t_render *render)
{
	int	update;

	pthread_mutex_lock(&render->update_mutex);
	update = render->update;
	pthread_mutex_unlock(&render->update_mutex);
	return (update);
}

void	set_render_update(t_render *render, int update)
{
	pthread_mutex_lock(&render->update_mutex);
	render->update = update;
	pthread_mutex_unlock(&render->update_mutex);
}
