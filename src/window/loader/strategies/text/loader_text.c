/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:01:38 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/27 17:15:10 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loader_text.h"
#include "../../helpers/loader_helper.h"

// TODO: Own text with imgs!!
void	paint_text(t_loader *loader, t_size img_size)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (loader_is_alive(loader) && i < img_size.width)
	{
		j = 0;
		while (loader_is_alive(loader) && j < img_size.height)
		{
			pthread_mutex_lock(&loader->img_mutex);
			mlx_put_pixel(loader->image, i, j, 0xfffffff);
			pthread_mutex_unlock(&loader->img_mutex);
			j++;
		}
		i++;
	}
}