/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:09:33 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:50:11 by cfidalgo         ###   ########.fr       */
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
