/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:08 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/06 17:32:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_settings.h"

void	print_scene_settings(t_scene_settings *settings)
{
	printf("Settings: %s | %f, %f, %f | %u | %d | %u\n",
		settings->name,
		settings->sky_color.red, settings->sky_color.green,
		settings->sky_color.blue,
		settings->samples,
		settings->antialiasing,
		settings->max_depth);
}

void	init_scene_settings(t_scene_settings *settings)
{
	settings->samples = 1;
	settings->antialiasing = 0;
	settings->max_depth = 1;
}

void	destroy_scene_settings(t_scene_settings *settings)
{
	free(settings->name);
}
