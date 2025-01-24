/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:08 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"
#include "utils/utils_bonus_bonus.h"
#include "scene_settings_bonus.h"
#include <stdio.h>
#include <stdlib.h>

void	print_scene_settings(t_scene_settings *settings)
{
	printf("Settings: %s | %f, %f, %f\n",
		settings->name,
		settings->sky_color.red, settings->sky_color.green,
		settings->sky_color.blue);
}

void	set_scene_defaults(t_scene_settings *settings, char *filename)
{
	settings->name = get_file_name(filename, FILE_EXTENSION);
	settings->sky_color.red = 0.839215686;
	settings->sky_color.green = 0.956862745;
	settings->sky_color.blue = 1;
	settings->sky_box = NULL;
}

void	destroy_scene_settings(t_scene_settings *settings)
{
	free(settings->name);
	free_figures(settings->sky_box);
}
