/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:09:25 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/29 17:58:31 by arcanava         ###   ########.fr       */
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
	return (alive);
}

void	loader_set_alive(t_loader *loader, int alive)
{
	pthread_mutex_lock(&loader->alive_mutx);
	loader->alive = alive;
	pthread_mutex_unlock(&loader->alive_mutx);
}

void	loader_set_img_enabled(t_loader	*loader, int enabled)
{
	pthread_mutex_lock(&loader->img_mutex);
	loader->image->enabled = enabled;
	pthread_mutex_unlock(&loader->img_mutex);
}

int	loader_to_resize(t_loader *loader)
{
	int	resize;

	pthread_mutex_lock(&loader->img_mutex);
	resize = loader->resize;
	pthread_mutex_unlock(&loader->img_mutex);
	return (resize);
}

void	loader_set_resize(t_loader *loader, int resize)
{
	pthread_mutex_lock(&loader->img_mutex);
	loader->resize = resize;
	pthread_mutex_unlock(&loader->img_mutex);
}
