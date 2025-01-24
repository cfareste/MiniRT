/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_cursor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:59:49 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_cursor_bonus.h"

void	cursor_update_pos(double x, double y, t_cursor *cursor)
{
	pthread_mutex_lock(&cursor->mutex);
	cursor->pos.x = x;
	cursor->pos.y = y;
	pthread_mutex_unlock(&cursor->mutex);
}

t_cursor_pos	cursor_get_pos(t_cursor *cursor)
{
	t_cursor_pos	pos;

	pthread_mutex_lock(&cursor->mutex);
	pos = cursor->pos;
	pthread_mutex_unlock(&cursor->mutex);
	return (pos);
}

void	init_cursor(t_cursor *cursor)
{
	pthread_mutex_init(&cursor->mutex, NULL);
}
