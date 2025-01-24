/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:40:38 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 19:02:10 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene/scene.h"
#include "scene/figure/parser/figure_parser.h"
#include "scene/camera/parser/camera_parser.h"
#include "scene/light/ambient_light/ambient_light.h"
#include "scene/light/parser/light_parser.h"
#include "../settings/parser/scene_settings_parser.h"
#include "parser/helpers/parser_helper.h"

void	check_scene_parsing(t_parser_ctx *ctx, t_scene *scene)
{
	t_light	*lights;
	int		mandatory_lights;

	ctx->line = 0;
	if (!scene->camera)
		throw_parse_err(ctx, "No camera provided for scene");
	lights = scene->lights;
	if (!scene->ambient_light)
		throw_parse_err(ctx, "Ambient light is missing!");
	mandatory_lights = 0;
	while (lights && mandatory_lights < 2)
	{
		if (lights->type == LIGHT_ID_MANDATORY)
			mandatory_lights++;
		lights = lights->next;
	}
	if (mandatory_lights > 1)
		throw_parse_err(ctx, "Only 1 mandatory light (L) is allowed");
}

int	try_parse_scene_elems(t_parser_ctx *ctx, char **args,
				t_scene *scene)
{
	int	is_char;

	is_char = ft_strlen(args[0]) == 1;
	if (is_char && *args[0] == AMBIENT_LIGHT_ID)
		parse_ambient_light(ctx, args, &scene->ambient_light);
	else if (is_char && *args[0] == CAMERA_ID[0])
	{
		parse_camera(ctx, args, &scene->camera);
		scene->orig_camera = *scene->camera;
	}
	else if (is_char && (*args[0] == LIGHT_ID_MANDATORY
			|| *args[0] == LIGHT_ID))
		parse_light(ctx, args, &scene->lights);
	else if (*args[0] == *SCENE_SETTINGS_ID)
	{
		if (!try_parse_scene_setting(ctx, args, &scene->settings))
			return (0);
	}
	else if (!try_parse_figure(ctx, args, &scene->figures))
		return (0);
	return (1);
}
