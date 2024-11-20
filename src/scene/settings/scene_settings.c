/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:08 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/20 14:48:12 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_settings.h"

void	print_scene_settings(t_scene_settings *settings)
{
	printf("Settings: %s | %f, %f, %f\n",
		settings->name,
		settings->sky_color.red, settings->sky_color.green,
		settings->sky_color.blue);
}

void	init_scene_settings(t_scene_settings *settings)
{
	settings->sky_color.red = 0.839215686;
	settings->sky_color.green = 0.956862745;
	settings->sky_color.blue = 1;
}

void	destroy_scene_settings(t_scene_settings *settings)
{
	free(settings->name);
}
