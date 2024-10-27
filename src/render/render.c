/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:56:24 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helpers/render_helper.h"
#include "loader/helpers/loader_helper/loader_helper.h"
#include "window/helpers/window_helper.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/scene/light/utils/light_utils.h"
#include "render/scene/light/ambient_light/ambient_light.h"
#include <math.h>

void	check_collisions(t_scene *scene, t_hit_record *hit_record, int i, int j)
{
	t_ray		ray;
	t_figure	*figure;

	hit_record->distance = FLT_MAX;
	figure = scene->figures;
	set_ray_from_camera(&ray, scene->camera, i, j);
	while (figure)
	{
		if (figure->hit(figure, &ray, &hit_record->distance))
			set_hit_record(hit_record, &ray, figure);
		figure = figure->next;
	}
}

void	check_lights(t_hit_record *hit_record, t_scene *scene, t_color *color)
{
	t_ray		shadow_ray;
	t_light		*light;
	t_figure	*figure;
	float		distance;

	light = scene->lights;
	while (light)
	{
		set_shadow_ray(&shadow_ray, &hit_record->point, &light->position);
		figure = scene->figures;
		while (figure)
		{
			if (figure != hit_record->figure
				&& figure->hit(figure, &shadow_ray, &distance))
				break ;
			figure = figure->next;
		}
		if (!figure)
		{
			compute_diffuse(&shadow_ray, hit_record, light, color);
			compute_specular(scene, get_reflection(&shadow_ray, hit_record),
				light, color);
		}
		light = light->next;
	}
}

int	process_lighting(t_scene *scene, t_hit_record *hit_record)
{
	t_color	light_color;
	t_color	final_color;

	light_color.red = 0.0;
	light_color.green = 0.0;
	light_color.blue = 0.0;
	if (!hit_record->figure)
		return (get_sky_color(scene->ambient_light));
	apply_ambient_lighting(scene->ambient_light, &light_color);
	check_lights(hit_record, scene, &light_color);
	final_color.red = light_color.red * hit_record->figure->color.red;
	final_color.green = light_color.green * hit_record->figure->color.green;
	final_color.blue = light_color.blue * hit_record->figure->color.blue;
	return (get_color_value(&final_color));
}

void	render_scene(t_render *render, t_scene *scene, t_size size)
{
	unsigned int	i;
	unsigned int	j;
	int				color;
	t_hit_record	hit_record;

	set_viewport(scene->camera, &scene->camera->viewport, size);
	i = 0;
	while (!is_render_finished(render) && i < size.width)
	{
		j = 0;
		while (!is_render_finished(render) && j < size.height)
		{
			ft_bzero(&hit_record, sizeof(t_hit_record));
			check_collisions(scene, &hit_record, i, j);
			color = process_lighting(scene, &hit_record);
			pthread_mutex_lock(&render->image_mutex);
			if (!is_render_finished(render) && render->image
				&& i < render->image->width && j < render->image->height)
				mlx_put_pixel(render->image, i, j, color);
			pthread_mutex_unlock(&render->image_mutex);
			add_loader_progress(&render->loader);
			j++;
		}
		i++;
	}
}

void	init_render(t_render *render, mlx_t *mlx)
{
	pthread_mutex_init(&render->render_mutex, NULL);
	pthread_mutex_init(&render->image_mutex, NULL);
	render->image = mlx_new_image(mlx, mlx->width, mlx->height);
	put_image(render->image, mlx, NULL);
	init_loader(&render->loader, mlx);
}
