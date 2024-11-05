/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:08 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/05 15:26:55 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_settings.h"

void	print_scene_settings(t_scene_settings *settings)
{
	printf("Settings: %s | %f, %f, %f | %u | %f | %f | %u\n",
		settings->name,
		settings->sky_color.red, settings->sky_color.green,
		settings->sky_color.blue,
		settings->samples,
		settings->antialiasing_rad,
		settings->bokeh_rad,
		settings->max_depth);
}

void	init_scene_settings(t_scene_settings *settings)
{
	settings->samples = 1;
	settings->max_depth = 1;
}

void	destroy_scene_settings(t_scene_settings *settings)
{
	free(settings->name);
}
