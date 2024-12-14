/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   async_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:25:35 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/14 14:41:10 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "async_flag.h"

void	init_async_flag(t_async_flag *flag, int value)
{
	pthread_mutex_init(&flag->mutex, NULL);
	set_async_flag(flag, value);
}

void	set_async_flag(t_async_flag *flag, int value)
{
	pthread_mutex_lock(&flag->mutex);
	flag->value = value;
	pthread_mutex_unlock(&flag->mutex);
}

int	get_async_flag(t_async_flag *flag)
{
	int	value;

	pthread_mutex_lock(&flag->mutex);
	value = flag->value;
	pthread_mutex_unlock(&flag->mutex);
	return (value);
}

void	toggle_async_flag(t_async_flag *flag)
{
	pthread_mutex_lock(&flag->mutex);
	flag->value = !flag->value;
	pthread_mutex_unlock(&flag->mutex);
}
