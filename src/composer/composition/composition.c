/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:28:11 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 17:38:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composition.h"
#include "utils/utils_bonus.h"
#include "./helpers/lights/composition_lights_helpers.h"
#include "./helpers/figures/composition_figures_helpers.h"
#include "./helpers/settings/composition_settings_helpers.h"
#include "libft.h"

static int	fill_buffer(t_composer *composer, char **buffer)
{
	*buffer = NULL;
	if (fill_render(composer, composer->render, buffer)
		|| fill_scene(composer, &composer->render->scene, buffer)
		|| fill_window(composer, composer->render, buffer)
		|| fill_ambient(composer, composer->render->scene.ambient_light, buffer)
		|| fill_lights(composer, composer->render->scene.lights, buffer)
		|| fill_camera(composer, composer->render->scene.camera, buffer)
		|| fill_figures(composer, composer->render->scene.figures, buffer))
		return (0);
	printf("BUFFER::::\n%s\n", *buffer);
	return (0);
}

void	*composition_routine(t_composition *composition)
{
	char	*compose_buffer;
	int		buffer_length;

	(void) buffer_length;
	if (!composer_is_alive(composition->composer))
		return (free(composition), NULL);
	set_async_flag(&composition->composer->render->blocked, 1);
	buffer_length = fill_buffer(composition->composer, &compose_buffer);
	if (composer_is_alive(composition->composer))
	{
		(void) NULL;
	}
	composer_set_alive(composition->composer, 0);
	set_async_flag(&composition->composer->render->blocked, 0);
	free(compose_buffer);
	return (free(composition), NULL);
}
