/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:28:11 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/17 15:31:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composition.h"
#include "utils/utils_bonus.h"
#include "libft.h"

static int	fill_buffer(char **buffer)
{
	int	buff_len;

	*buffer = ft_calloc(1, sizeof(char));
	if (!*buffer)
		throw_sys_error("tryting to allocate composer buffer");
	buff_len = 0;
	return (buff_len);
}

// static void	dup_render(t_render *render)
// {
// 	render->samples;
// 	render->max_depth;
// 	render->antialiasing;
// 	render->strategy;
// 	render->soft_shadows_radius;

// 	render->scene.settings.name;
// 	render->scene.settings.sky_color;
// 	render->scene.settings.sky_box->bump_map.texture;

// 	render->image_mutex;
// 	render->image->width;
// 	render->image->height;

// 	render->scene.ambient_light->brightness;
// 	render->scene.ambient_light->color;

// 	render->scene.lights->position;
// 	render->scene.lights->brightness;
// 	render->scene.lights->color;

// 	render->scene.camera->position;
// 	render->scene.camera->front;
// 	render->scene.camera->fov;
// 	render->scene.camera->defocus;
// 	render->scene.camera->focus_dist;
// }

// dup_render();
void	*composition_routine(t_composition *composition)
{
	char	*compose_buffer;
	int		buffer_length;

	(void) buffer_length;
	if (!composer_is_alive(composition->composer))
		return (free(composition), NULL);
	buffer_length = fill_buffer(&compose_buffer);
	if (composer_is_alive(composition->composer))
	{
		(void) NULL;
	}
	composer_set_alive(composition->composer, 0);
	free(compose_buffer);
	return (free(composition), NULL);
}
