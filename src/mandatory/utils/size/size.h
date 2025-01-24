/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:43 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:19:13 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <pthread.h>

typedef struct s_window_size
{
	unsigned int	width;
	unsigned int	height;
	pthread_mutex_t	mutex;
}	t_size;

void	set_size(t_size *size, unsigned int width, unsigned int height);

t_size	get_size(t_size *size);
