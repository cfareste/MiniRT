/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:59:49 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/06 20:15:29 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_cursor.h"

void	cursor_update_pos(t_cursor *cursor, double x, double y)
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
