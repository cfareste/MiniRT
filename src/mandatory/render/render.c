/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:17:09 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "libft.h"
#include "window/helpers/window_helper.h"
#include "render/ray/helpers/ray_helper.h"
#include "renderer/renderer.h"
#include "strategies/raytracing/raytracing.h"

static void	render_pixel(t_render *render, t_iterators *iter)
{
	t_ray			ray;
	t_color			pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	set_ray_from_camera(&ray, render, iter);
	compute_raytracing(render, &ray, &pixel_color);
	mlx_put_pixel(render->image, iter->i, iter->j,
		get_color_value(&pixel_color));
}

void	*render_parts(t_render *render)
{
	t_iterators		px_iter;
	uint32_t		i;
	uint32_t		j;
	

	i = 0;
	while (i < render->image->width)
	{
		px_iter.i = i;
		j = 0;
		while (j < render->image->height)
		{
			px_iter.j = j;
			render_pixel(render, &px_iter);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	init_render(t_render *render, mlx_t *mlx)
{
	render->image = mlx_new_image(mlx, mlx->width, mlx->height);
	mlx_image_to_window(mlx, render->image, 0, 0);
}
