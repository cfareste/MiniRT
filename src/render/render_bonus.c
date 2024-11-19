/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 21:24:20 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helpers/render_helper_bonus.h"
#include "loader/helpers/loader_helper/loader_helper_bonus.h"
#include "window/helpers/window_helper_bonus.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/utils/thread/thread.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "render/utils/iterators/iterators.h"
#include "render/strategies/strategies.h"
#include <math.h>

static void	render_pixel(t_render_part *part, t_iterators *iterators,
	uint32_t *seed)
{
	unsigned int	k;
	t_ray			ray;
	t_color			pixel_color;
	t_color			sample_color;
	t_scene			*scene;

	k = 0;
	scene = &part->render->scene;
	ft_bzero(&pixel_color, sizeof(t_color));
	ft_bzero(&sample_color, sizeof(t_color));
	while (k < scene->settings.samples)
	{
		set_ray_from_camera(&ray, scene, iterators, seed);
		if (scene->settings.raytracing)
			compute_raytracing(scene, &ray, &sample_color);
		else
			compute_pathtracing(scene, &ray, &sample_color, seed);
		k++;
	}
	multiply_color_scalar(&sample_color,
		1 / (float) scene->settings.samples, &pixel_color);
	mlx_put_pixel(part->render->image, iterators->i, iterators->j,
		get_color_value(&pixel_color));
}

void	*render_part(t_render_part *part)
{
	uint32_t		seed;
	t_iterators		iterators;

	get_thread_id(&part->thread, &seed);
	iterators.j = 0;
	while (!is_render_finished(part->render)
		&& iterators.j < part->img_size.height)
	{
		iterators.i = part->min_size.height;
		while (!is_render_finished(part->render)
			&& iterators.i < part->img_size.width)
		{
			render_pixel(part, &iterators, &seed);
			add_loader_progress(&part->render->loader);
			iterators.i += part->render->parts_amount;
		}
		iterators.j++;
	}
	return (NULL);
}

void	init_render(t_render *render, mlx_t *mlx)
{
	pthread_mutex_init(&render->mutex, NULL);
	pthread_mutex_init(&render->image_mutex, NULL);
	render->image = mlx_new_image(mlx, mlx->width, mlx->height);
	put_image(render->image, mlx, NULL);
	init_loader(&render->loader, mlx);
}
