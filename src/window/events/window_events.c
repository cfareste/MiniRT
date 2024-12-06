/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:42:36 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/06 23:09:21 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "window_events.h"
#include "render/render_bonus.h"
#include "render/renderer/renderer_bonus.h"
#include "render/events/render_events.h"
#include "scene/camera/helpers/camera_helper.h"
#include "scene/camera/events/camera_events.h"
#include "scene/selection/scene_selection.h"

void	key_hook(mlx_key_data_t keydata, t_window *window)
{
	t_figure	*selection;

	selection = get_selection_fig(&window->render.scene);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			close_window(window);
		else if (keydata.key == MLX_KEY_E)
			export_image(&window->exporter, &window->jobs);
		else if (keydata.key == MLX_KEY_L)
			loader_toggle_visibility(window->exporter.loader);
		else if (!selection && keydata.key == MLX_KEY_P)
			set_selection_fig(&window->render.scene,
				window->render.scene.figures);
	}
	composer_key_events(&keydata, window);
	if (selection)
	{
		selection_key_events(&keydata, window);
		ft_bzero(&window->render.scene.camera->controls,
			sizeof(t_camera_controls));
		return ;
	}
	render_key_events(&keydata, window);
	camera_key_events(&keydata, window);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_window		*window;

	(void) xdelta;
	window = (t_window *) param;
	if (window->render.blocked || mlx_get_time() - window->last_scroll < 0.2)
		return ;
	stop_render(&window->render);
	if (ydelta <= -1.0)
		update_camera_fov(window->render.scene.camera, 1);
	else if (ydelta >= 1.0)
		update_camera_fov(window->render.scene.camera, -1);
	else
		return ;
	window->last_scroll = mlx_get_time();
	render(window);
}

void	resize_hook(int32_t width, int32_t height, t_window *window)
{
	window->resize.last_resize = 1;
	window->resize.size.width = width;
	window->resize.size.height = height;
}

void	mouse_hook(mouse_key_t button, action_t action,
			modifier_key_t mods, t_window *window)
{
	t_cursor_pos	cursor_pos;

	(void) mods;
	cursor_pos = cursor_get_pos(&window->cursor);
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		printf("Clicked %f, %f\n", cursor_pos.x, cursor_pos.y);
}
