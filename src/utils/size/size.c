/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:41 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 18:46:11 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "size.h"

t_size	new_size(int width, int height)
{
	t_size	size;

	size.width = width;
	size.height = height;
	return (size);
}

void	set_size(t_size *size, unsigned int width, unsigned int height)
{
	pthread_mutex_lock(&size->mutex);
	size->width = width;
	size->height = height;
	pthread_mutex_unlock(&size->mutex);
}

t_size	get_size(t_size *size)
{
	t_size	new;

	pthread_mutex_lock(&size->mutex);
	new = new_size(size->width, size->height);
	pthread_mutex_unlock(&size->mutex);
	return (new);
}
