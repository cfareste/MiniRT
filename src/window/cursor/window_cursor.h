/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_cursor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:58:42 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/06 20:05:07 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <pthread.h>

typedef struct s_cursor_pos
{
	double	x;
	double	y;
}	t_cursor_pos;

typedef struct s_cursor
{
	t_cursor_pos	pos;
	pthread_mutex_t	mutex;
}	t_cursor;

void			cursor_update_pos(t_cursor *cursor, double x, double y);

t_cursor_pos	cursor_get_pos(t_cursor *cursor);

void			init_cursor(t_cursor *cursor);
