/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/05 22:34:08 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helpers/render_helper_bonus.h"
#include "window/helpers/window_helper_bonus.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/utils/thread/thread.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "utils/iterators/iterators.h"
#include "render/strategies/strategies.h"
#include <math.h>

static void	compute_strategy(t_render_part *part, t_ray *ray,
	t_color *sample_color, uint32_t *seed)
{
	if (part->render->strategy == RAYTRACING)
		compute_raytracing(part->render, ray, sample_color, seed);
	else if (part->render->strategy == PATHTRACING)
		compute_pathtracing(part->render, ray, sample_color, seed);
	else if (part->render->strategy == NORMAL_MAP)
		compute_normal_map(&part->render->scene, ray, sample_color);
}

static void	render_pixel(t_render_part *part, t_iterators *iterators,
	uint32_t *seed)
{
	unsigned int	k;
	t_ray			ray;
	t_color			pixel_color;
	t_color			sample_color;

	k = 0;
	ft_bzero(&pixel_color, sizeof(t_color));
	ft_bzero(&sample_color, sizeof(t_color));
	while (k < part->render->samples)
	{
		set_ray_from_camera(&ray, part->render, iterators, seed);
		compute_strategy(part, &ray, &sample_color, seed);
		k++;
		if (part->render->strategy == NORMAL_MAP)
			break ;
	}
	multiply_color_scalar(&sample_color, 1 / (float) k, &pixel_color);
	mlx_put_pixel(part->render->image, iterators->i, iterators->j,
		get_color_value(&pixel_color));
}

void	*render_part(t_render_part *part)
{
	uint32_t	seed;
	t_pixel		*pixels;
	t_iterators	iterators;
	size_t		i;

	get_thread_id(&part->thread, &seed);
	pixels = part->pixels;
	i = 0;
	while (!is_render_finished(part->render)
		&& i < part->pixels_amount)
	{
		iterators.i = pixels[i].x;
		iterators.j = pixels[i].y;
		render_pixel(part, &iterators, &seed);
		i++;
	}
	return (NULL);
}

void	set_render_defaults(t_render *render)
{
	render->samples = 1;
	render->antialiasing = 0;
	render->strategy = PATHTRACING;
	render->max_depth = 1;
	render->soft_shadows_radius = 0;
}

void	init_render(t_render *render, mlx_t *mlx)
{
	pthread_mutex_init(&render->mutex, NULL);
	pthread_mutex_init(&render->image_mutex, NULL);
	pthread_mutex_init(&render->resize_mutex, NULL);
	render->resize = 1;
	render->image = mlx_new_image(mlx, mlx->width, mlx->height);
	put_image(render->image, mlx, NULL);
	mlx_set_instance_depth(render->image->instances
		+ render->image->count - 1, 0);
}
