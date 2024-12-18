/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:28:11 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 02:01:47 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composition.h"
#include "utils/utils_bonus.h"
#include "libft.h"

static void	join_buff_string(char **buffer, char *title, char *str, char sep)
{
	if (!str)
		throw_sys_error("allocating composer setting in buffer");
	if (title)
		push_str(buffer, title, throw_sys_error, "joining buffer with title");
	push_str(buffer, str, throw_sys_error, "joining buffer with string");
	push_char(buffer, sep, throw_sys_error, "joining space char with buffer");
	free(str);
}

static char	*get_strategy_name(t_strategy strategy)
{
	char	*strategy_name;

	if (strategy == NORMAL_MAP)
		strategy_name = "normal_map ";
	else
		strategy_name = "raytracing ";
	return (strategy_name);
}

static char	*colortoa(t_color *color)
{
	char	*red_str;
	char	*green_str;
	char	*blue_str;
	char	*color_str;

	red_str = ft_itoa(color->red * 255);
	green_str = ft_itoa(color->green * 255);
	blue_str = ft_itoa(color->blue * 255);
	if (!red_str || !green_str || !blue_str)
		throw_sys_error("allocating color components strings");
	color_str = NULL;
	push_str(&color_str, red_str, throw_sys_error, "pushing color component");
	push_char(&color_str, ',', throw_sys_error, "pushing color component");
	push_str(&color_str, green_str, throw_sys_error, "pushing color component");
	push_char(&color_str, ',', throw_sys_error, "pushing color component");
	push_str(&color_str, blue_str, throw_sys_error, "pushing color component");
	free(red_str);
	free(green_str);
	free(blue_str);
	return (color_str);
}

static char	*coordtoa(t_coordinates *coords)
{
	char	*x_str;
	char	*y_str;
	char	*z_str;
	char	*coords_str;

	x_str = ft_dtoa(coords->x, 3);
	y_str = ft_dtoa(coords->y, 3);
	z_str = ft_dtoa(coords->z, 3);
	if (!x_str || !y_str || !z_str)
		throw_sys_error("allocating coordinates components strings");
	coords_str = NULL;
	push_str(&coords_str, x_str, throw_sys_error, "pushing coords component");
	push_char(&coords_str, ',', throw_sys_error, "pushing coords component");
	push_str(&coords_str, y_str, throw_sys_error, "pushing coords component");
	push_char(&coords_str, ',', throw_sys_error, "pushing coords component");
	push_str(&coords_str, z_str, throw_sys_error, "pushing coords component");
	free(x_str);
	free(y_str);
	free(z_str);
	return (coords_str);
}

static int	fill_render(t_composer *composer, t_render *render, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "R ", throw_sys_error, "pushing render setting string");
	if (render->samples)
		join_buff_string(buffer, SAMPLES_TITLE, ft_ultoa(render->samples), ' ');
	if (render->max_depth != 4)
		join_buff_string(buffer, MAX_DEPTH_TITLE, ft_ultoa(render->max_depth),
			' ');
	if (render->antialiasing)
		push_str(buffer, "antialiasing ",
			throw_sys_error, "pushing antialiasing string to buffer");
	if (render->strategy)
		push_str(buffer, get_strategy_name(render->strategy),
			throw_sys_error, "pushing strategy string to buffer");
	if (render->soft_shadows_radius)
		join_buff_string(buffer, SOFT_SHADOWS_TITLE, ft_ultoa(render->samples),
			' ');
	push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
	return (0);
}

static int	fill_scene(t_composer *composer, t_scene *scene, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "S ", throw_sys_error, "pushing scene setting string");
	join_buff_string(buffer, SCENE_NAME_TITLE, ft_strdup(scene->settings.name),
		' ');
	join_buff_string(buffer, SKY_TITLE, colortoa(&scene->settings.sky_color),
		' ');
	if (scene->settings.sky_box)
		join_buff_string(buffer, SKY_BOX_TITLE,
			ft_strdup(scene->settings.sky_box->bump_map.texture->path), ' ');
	push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
	return (0);
}

static int	fill_window(t_composer *composer, t_render *render, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "W ", throw_sys_error, "pushing window setting string");
	join_buff_string(buffer, WIN_WIDTH_TITLE, ft_ultoa(render->image->width),
		' ');
	join_buff_string(buffer, WIN_HEIGHT_TITLE, ft_ultoa(render->image->height),
		'\n');
	return (0);
}

static int	fill_ambiental(t_composer *composer, t_light *ambiental,
	char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "A ", throw_sys_error, "pushing ambiental setting string");
	join_buff_string(buffer, NULL, ft_dtoa(ambiental->brightness, 3), ' ');
	join_buff_string(buffer, NULL, colortoa(&ambiental->color), '\n');
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
		push_char(buffer, ' ', throw_sys_error, "pushing whitespace");
		join_buff_string(buffer, NULL, coordtoa(&light->position), ' ');
		join_buff_string(buffer, NULL, ft_dtoa(light->brightness, 2), ' ');
		join_buff_string(buffer, NULL, colortoa(&light->color), '\n');
		light = light->next;
	}
	return (0);
}

static int	fill_camera(t_composer *composer, t_camera *camera, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "C ", throw_sys_error, "pushing camera setting string");
	join_buff_string(buffer, NULL, coordtoa(&camera->position), ' ');
	join_buff_string(buffer, NULL, coordtoa(&camera->front), ' ');
	join_buff_string(buffer, NULL, ft_itoa(camera->fov), ' ');
	if (camera->defocus != 0.0)
		join_buff_string(buffer, NULL, ft_dtoa(camera->defocus, 3), ' ');
	if (camera->focus_dist != 1.0)
		join_buff_string(buffer, NULL, ft_dtoa(camera->focus_dist, 3), ' ');
	push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
	return (0);
}

static int	fill_figures(t_composer *composer, t_figure *figures, char **buffer)
{
	t_figure	*figure;

	if (!composer_is_alive(composer))
		return (1);
	figure = figures;
	while (figure && composer_is_alive(composer))
	{
		push_str(buffer, figure->type, throw_sys_error, "pushing figure type");
		push_char(buffer, ' ', throw_sys_error, "pushing whitespace");
		join_buff_string(buffer, NULL, coordtoa(&figure->position), ' ');
		join_buff_string(buffer, NULL, colortoa(&figure->color), ' ');
		if (figure->glossiness != 256)
			join_buff_string(buffer, GLOSSINESS_TITLE,
				ft_dtoa(figure->glossiness, 3), ' ');
		if (figure->pattern.dimension)
		{
			push_str(buffer, COLOR_DISRUPTION_TITLE,
				throw_sys_error, "pushing cd to buffer");
			join_buff_string(buffer, NULL,
				colortoa(&figure->pattern.colors[0]), ':');
			join_buff_string(buffer, NULL,
				colortoa(&figure->pattern.colors[1]), ':');
			join_buff_string(buffer, NULL,
				ft_dtoa(figure->pattern.dimension, 8), ' ');
		}
		if (figure->bump_map.texture)
		{
			push_str(buffer, BUMP_MAP_TITLE,
				throw_sys_error, "pushing bm to buffer");
			push_str(buffer, figure->bump_map.texture->path,
				throw_sys_error, "pushing texture path to buffer");
			push_char(buffer, ':', throw_sys_error, "pushing separator");
			join_buff_string(buffer, NULL,
				ft_dtoa(figure->bump_map.width_dim, 8), ':');
			if (figure->bump_map.format != OPENGL)
				push_str(buffer, "directx",
					throw_sys_error, "pushing texture format");
		}
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
