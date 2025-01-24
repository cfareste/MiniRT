/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   async_flag.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:24:26 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/17 12:44:49 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <pthread.h>

typedef struct s_async_flag
{
	int				value;
	pthread_mutex_t	mutex;
}	t_async_flag;

void	init_async_flag(t_async_flag *flag, int value);

void	set_async_flag(t_async_flag *flag, int value);

int		get_async_flag(t_async_flag *flag);

int		toggle_async_flag(t_async_flag *flag);
