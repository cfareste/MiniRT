/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition_settings_helpers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:23:17 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 12:58:36 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composition_settings_helpers.h"
#include "utils/utils_bonus.h"
#include "libft.h"

static char	*get_strategy_name(t_strategy strategy)
{
	char	*strategy_name;

	if (strategy == NORMAL_MAP)
		strategy_name = "normal_map ";
	else
		strategy_name = "raytracing ";
	return (strategy_name);
}

int	fill_render(t_composer *composer, t_render *render, char **buffer)
{
	t_strategy	strategy;

	strategy = get_async_flag(&render->strategy);
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "R ", throw_sys_error, "pushing render setting string");
	if (render->samples && render->samples != (unsigned long) -1)
		join_format_str(buffer, SAMPLES_TITLE, ft_ultoa(render->samples), SEP);
	if (render->max_depth != 4)
		join_format_str(buffer, MAX_DEPTH_TITLE, ft_ultoa(render->max_depth),
			SEP);
	if (!render->antialiasing)
		push_str(buffer, "antialiasing:0\t",
			throw_sys_error, "pushing antialiasing");
	if (strategy != PATHTRACING)
		push_str(buffer, get_strategy_name(strategy),
			throw_sys_error, "pushing strategy string to buffer");
	if (render->soft_shadows_radius != 1.0)
		join_format_str(buffer, SOFT_SHADOWS_TITLE,
			ft_dtoa(render->soft_shadows_radius, 3), SEP);
	push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
	return (0);
}

int	fill_scene(t_composer *composer, t_scene *scene, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "S ", throw_sys_error, "pushing scene setting string");
	join_format_str(buffer, SCENE_NAME_TITLE, ft_strdup(scene->settings.name),
		SEP);
	join_format_str(buffer, SKY_TITLE, colortoa(&scene->settings.sky_color),
		SEP);
	if (scene->settings.sky_box)
		join_format_str(buffer, SKY_BOX_TITLE,
			ft_strdup(scene->settings.sky_box->bump_map.texture->path), SEP);
	push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
	return (0);
}

int	fill_window(t_composer *composer, t_render *render, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "W ", throw_sys_error, "pushing window setting string");
	join_format_str(buffer, WIN_WIDTH_TITLE, ft_ultoa(render->image->width),
		SEP);
	join_format_str(buffer, WIN_HEIGHT_TITLE, ft_ultoa(render->image->height),
		'\n');
	return (0);
}

int	fill_camera(t_composer *composer, t_camera *camera, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "C ", throw_sys_error, "pushing camera setting string");
	join_format_str(buffer, NULL, coordtoa(&camera->position, 3), SEP);
	join_format_str(buffer, NULL, coordtoa(&camera->front, 3), SEP);
	join_format_str(buffer, NULL, ft_itoa(camera->fov), SEP);
	if (camera->defocus != 0.0)
		join_format_str(buffer, NULL, ft_dtoa(camera->defocus, 3), SEP);
	if (camera->focus_dist != 1.0)
		join_format_str(buffer, NULL, ft_dtoa(camera->focus_dist, 3), SEP);
	push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
	return (0);
}
