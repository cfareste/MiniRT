/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:09:25 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/26 19:12:35 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "loader_helper.h"

int	loader_is_alive(t_loader *loader)
{
	int	alive;

	pthread_mutex_lock(&loader->alive_mutx);
	alive = loader->alive;
	pthread_mutex_unlock(&loader->alive_mutx);
	printf("ALIVE: %d\n", alive);
	return (alive);
}

void	loader_set_alive(t_loader *loader, int alive)
{
	pthread_mutex_lock(&loader->alive_mutx);
	loader->alive = alive;
	pthread_mutex_unlock(&loader->alive_mutx);
	printf("set ALIVE: %d\n", alive);
}

void	loader_set_img_enabled(t_loader	*loader, int enabled)
{
	pthread_mutex_lock(&loader->img_mutex);
	loader->image->enabled = enabled;
	pthread_mutex_unlock(&loader->img_mutex);
}
