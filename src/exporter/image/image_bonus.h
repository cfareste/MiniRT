/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:09:33 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 16:28:43 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "utils/size/size.h"

typedef struct s_image
{
	t_size	size;
	uint8_t	*pixels;
	char	*name;
}	t_image;

t_image	*image_dup(mlx_image_t *image, pthread_mutex_t *mutex);

void	destroy_image(t_image *image);
