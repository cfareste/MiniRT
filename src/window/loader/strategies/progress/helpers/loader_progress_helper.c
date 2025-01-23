/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_progress_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:05:47 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 17:57:11 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../loader_bonus.h"

double	get_progress_factor(t_progress *progress)
{
	double	factor;

	pthread_mutex_lock(&progress->mutex);
	factor = ((double) progress->current) / ((double) progress->total);
	pthread_mutex_unlock(&progress->mutex);
	return (factor);
}

void	loader_set_total(t_loader *loader, int total)
{
	pthread_mutex_lock(&loader->progress.mutex);
	loader->progress.total = total;
	pthread_mutex_unlock(&loader->progress.mutex);
}

void	loader_add_progress(t_loader *loader)
{
	pthread_mutex_lock(&loader->progress.mutex);
	loader->progress.current += 1;
	pthread_mutex_unlock(&loader->progress.mutex);
}
