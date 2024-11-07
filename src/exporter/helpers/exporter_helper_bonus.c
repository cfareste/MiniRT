/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_helper_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:09:24 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/07 13:09:24 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exporter_helper_bonus.h"

int	is_exporter_active(t_exporter *exporter)
{
	int	active;

	pthread_mutex_lock(&exporter->mutex);
	active = exporter->active;
	pthread_mutex_unlock(&exporter->mutex);
	return (active);
}

void	set_exporter_active(t_exporter *exporter, int active)
{
	pthread_mutex_lock(&exporter->mutex);
	exporter->active = active;
	pthread_mutex_unlock(&exporter->mutex);
}
