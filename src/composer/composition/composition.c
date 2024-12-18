/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:28:11 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 17:16:11 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composition.h"
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

static int	fill_render(t_composer *composer, t_render *render, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "R ", throw_sys_error, "pushing render setting string");
	if (render->samples)
		join_format_str(buffer, SAMPLES_TITLE, ft_ultoa(render->samples), SEP);
	if (render->max_depth != 4)
		join_format_str(buffer, MAX_DEPTH_TITLE, ft_ultoa(render->max_depth),
			' ');
	if (render->antialiasing)
		push_str(buffer, "antialiasing ",
			throw_sys_error, "pushing antialiasing string to buffer");
	if (render->strategy)
		push_str(buffer, get_strategy_name(render->strategy),
			throw_sys_error, "pushing strategy string to buffer");
	if (render->soft_shadows_radius)
		join_format_str(buffer, SOFT_SHADOWS_TITLE, ft_ultoa(render->samples),
			' ');
	push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
	return (0);
}

static int	fill_scene(t_composer *composer, t_scene *scene, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "S ", throw_sys_error, "pushing scene setting string");
	join_format_str(buffer, SCENE_NAME_TITLE, ft_strdup(scene->settings.name),
		' ');
	join_format_str(buffer, SKY_TITLE, colortoa(&scene->settings.sky_color),
		' ');
	if (scene->settings.sky_box)
		join_format_str(buffer, SKY_BOX_TITLE,
			ft_strdup(scene->settings.sky_box->bump_map.texture->path), SEP);
	push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
	return (0);
}

static int	fill_window(t_composer *composer, t_render *render, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "W ", throw_sys_error, "pushing window setting string");
	join_format_str(buffer, WIN_WIDTH_TITLE, ft_ultoa(render->image->width),
		' ');
	join_format_str(buffer, WIN_HEIGHT_TITLE, ft_ultoa(render->image->height),
		'\n');
	return (0);
}

static int	fill_ambiental(t_composer *composer, t_light *ambiental,
	char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "A ", throw_sys_error, "pushing ambiental setting string");
	join_format_str(buffer, NULL, ft_dtoa(ambiental->brightness, 3), SEP);
	join_format_str(buffer, NULL, colortoa(&ambiental->color), '\n');
	return (0);
}

static int	fill_lights(t_composer *composer, t_light *lights, char **buffer)
{
	t_light	*light;

	if (!composer_is_alive(composer))
		return (1);
	light = lights;
	while (light && composer_is_alive(composer))
	{
		push_char(buffer, light->type, throw_sys_error, "pushing light type");
		push_char(buffer, SEP, throw_sys_error, "pushing whitespace");
		join_format_str(buffer, NULL, coordtoa(&light->position), SEP);
		join_format_str(buffer, NULL, ft_dtoa(light->brightness, 2), SEP);
		join_format_str(buffer, NULL, colortoa(&light->color), '\n');
		light = light->next;
	}
	return (0);
}

static int	fill_camera(t_composer *composer, t_camera *camera, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "C ", throw_sys_error, "pushing camera setting string");
	join_format_str(buffer, NULL, coordtoa(&camera->position), SEP);
	join_format_str(buffer, NULL, coordtoa(&camera->front), SEP);
	join_format_str(buffer, NULL, ft_itoa(camera->fov), SEP);
	if (camera->defocus != 0.0)
		join_format_str(buffer, NULL, ft_dtoa(camera->defocus, 3), SEP);
	if (camera->focus_dist != 1.0)
		join_format_str(buffer, NULL, ft_dtoa(camera->focus_dist, 3), SEP);
	push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
	return (0);
}

static void	fill_glossiness(double glossiness, t_material *material,
	char **buffer)
{
	double	original_glossiness;

	original_glossiness = glossiness;
	if (material->type == METALLIC)
		original_glossiness /= (1.1 - material->metallic_attrs->roughness);
	else if (material->type == PLASTIC)
		original_glossiness /= (1.1 - material->plastic_attrs->roughness);
	if (original_glossiness != 256.0)
		join_format_str(buffer, GLOSSINESS_TITLE,
			ft_dtoa(original_glossiness, 3), SEP);
}

static void	fill_pattern(t_pattern *pattern, char **buffer)
{
	push_str(buffer, PATTERN_TITLE, throw_sys_error, "composing pattern");
	join_format_str(buffer, NULL, colortoa(&pattern->colors[0]), ':');
	join_format_str(buffer, NULL, colortoa(&pattern->colors[1]), ':');
	join_format_str(buffer, NULL, ft_dtoa(pattern->dimension, 8), SEP);
}

static void	fill_bump_map(t_bump_map *bump_map, t_texture *texture,
	char **buffer)
{
	push_str(buffer, BUMP_MAP_TITLE, throw_sys_error, "composing bump map");
	push_str(buffer, texture->path, throw_sys_error, "composing path");
	push_char(buffer, ':', throw_sys_error, "pushing separator");
	join_format_str(buffer, NULL, ft_dtoa(bump_map->width_dim, 8), ':');
	if (bump_map->format != OPENGL)
		push_str(buffer, "directx", throw_sys_error, "pushing texture format");
}

static int	fill_optional(t_composer *composer, t_figure *figure, char **buffer)
{
	t_material	*material;

	(void) composer;
	(void) figure;
	(void) buffer;
	(void) material;
	if (!composer_is_alive(composer))
		return (1);
	material = &figure->material;
	if (material->type != DIFFUSE)
		join_format_str(buffer, MATERIAL_TITLE,
			material->compose(material), '\0');
	fill_glossiness(figure->glossiness, &figure->material, buffer);
	if (figure->pattern.dimension)
		fill_pattern(&figure->pattern, buffer);
	if (figure->bump_map.texture)
		fill_bump_map(&figure->bump_map, figure->bump_map.texture, buffer);
	return (0);
}

static int	fill_figures(t_composer *composer, t_figure *figures, char **buffer)
{
	t_point		center;
	t_figure	*figure;

	if (!composer_is_alive(composer))
		return (1);
	figure = figures;
	while (figure && composer_is_alive(composer))
	{
		push_str(buffer, figure->type, throw_sys_error, "pushing figure type");
		push_char(buffer, SEP, throw_sys_error, "pushing whitespace");
		center = figure->position;
		if (ft_strcmp(figure->type, CONE_ID) == EQUAL_STRINGS)
			translate_point(&center, &figure->co_attrs->orientation,
				figure->co_attrs->height / 2.0, &center);
		join_format_str(buffer, NULL, coordtoa(&center), SEP);
		join_format_str(buffer, NULL, figure->compose(figure), '\0');
		join_format_str(buffer, NULL, colortoa(&figure->color), SEP);
		if (fill_optional(composer, figure, buffer))
			return (1);
		push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
		figure = figure->next;
	}
	return (0);
}

static int	fill_buffer(t_composer *composer, char **buffer)
{
	*buffer = NULL;
	if (fill_render(composer, composer->render, buffer)
		|| fill_scene(composer, &composer->render->scene, buffer)
		|| fill_window(composer, composer->render, buffer)
		|| fill_ambiental(composer, composer->render->scene.ambient_light,
			buffer)
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
