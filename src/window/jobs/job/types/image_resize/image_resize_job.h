/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_resize_job.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:51:06 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/26 14:00:26 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "../../job.h"

typedef struct s_resize_wrapper
{
	t_size	nsize;
	mlx_image_t *image;
}	t_resize_wrapper;

t_job	*init_img_resize_job(t_job *job, t_size	nsize, mlx_image_t *image);