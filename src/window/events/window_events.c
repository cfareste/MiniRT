/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:42:36 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/renderer/renderer.h"
#include "render/events/render_events.h"
#include "scene/camera/helpers/camera_helper.h"
#include "scene/camera/events/camera_events.h"
#include "scene/selection/scene_selection.h"
#include "composer/events/composer_events.h"
#include "scene/selection/helpers/scene_selection_helpers.h"

void	key_hook(mlx_key_data_t keydata, t_window *window)
{
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE)
		return (close_window(window));
	set_controls(&keydata, &window->controls);
	composer_key_events(&keydata, window);
	if (get_selection_fig(&window->render.scene))
		selection_key_events(&keydata, window);
	else
	{
		if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_X)
			export_image(&window->exporter, &window->jobs);
		else if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_L)
			loader_toggle_visibility(window->exporter.loader);
		render_key_events(&keydata, window);
		camera_key_events(&keydata, window);
	}
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_window		*window;

	(void) xdelta;
	window = (t_window *) param;
	if (get_async_flag(&window->render.blocked)
		|| mlx_get_time() - window->last_scroll < 0.2)
		return ;
	stop_render(&window->render);
	if (ydelta <= -1.0)
		update_camera_fov(window->render.scene.camera, 1);
	else if (ydelta >= 1.0)
		update_camera_fov(window->render.scene.camera, -1);
	else
		return ;
	window->last_scroll = mlx_get_time();
	set_async_flag(&window->render.update, 1);
}

void	resize_hook(int32_t width, int32_t height, t_window *window)
{
	window->resize.to_resize = 1;
	window->resize.size.width = width;
	window->resize.size.height = height;
}

void	mouse_hook(mouse_key_t button, action_t action,
			modifier_key_t mods, t_window *window)
{
	t_cursor_pos	cursor_pos;

	(void) mods;
	cursor_pos = cursor_get_pos(&window->cursor);
	if (get_async_flag(&window->render.blocked) || action != MLX_PRESS
		|| (button != MLX_MOUSE_BUTTON_LEFT
			&& button != MLX_MOUSE_BUTTON_RIGHT))
		return ;
	else if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		select_figure(&window->render, cursor_pos.x, cursor_pos.y);
	else if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
		deselect_figure(&window->render);
	set_async_flag(&window->render.update, 1);
}
