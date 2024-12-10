/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:13 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/10 15:00:44 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera_events.h"
#include "../helpers/camera_helper.h"
#include "render/renderer/renderer_bonus.h"
#include "scene/settings/sky_box/sky_box.h"

static int	set_control(int8_t *control, mlx_key_data_t *keydata, keys_t pos,
					keys_t neg)
{
	int8_t	mod;
	int8_t	factor;

	factor = 0;
	mod = 0;
	if (keydata->key == pos)
		factor = 1;
	else if (keydata->key == neg)
		factor = -1;
	else
		return (mod);
	if (keydata->action == MLX_PRESS)
		mod = 1;
	else if (keydata->action == MLX_RELEASE)
		mod = -1;
	factor *= mod;
	*control += factor;
	return (mod);
}

static void	movement_event(mlx_key_data_t *keydata, t_camera *camera)
{
	camera->controls.moving += set_control(&camera->controls.view_up,
			keydata, MLX_KEY_UP, MLX_KEY_DOWN);
	camera->controls.moving += set_control(&camera->controls.view_right,
			keydata, MLX_KEY_RIGHT, MLX_KEY_LEFT);
	camera->controls.moving += set_control(&camera->controls.move_up,
			keydata, MLX_KEY_SPACE, MLX_KEY_LEFT_SHIFT);
	camera->controls.moving += set_control(&camera->controls.move_front,
			keydata, MLX_KEY_W, MLX_KEY_S);
	camera->controls.moving += set_control(&camera->controls.move_right,
			keydata, MLX_KEY_D, MLX_KEY_A);
}

void	camera_key_events(mlx_key_data_t keydata, t_window *window)
{
	t_camera	*camera;

	if (!window->render.blocked
		&& keydata.action == MLX_PRESS && keydata.key == MLX_KEY_C)
	{
		stop_render(&window->render);
		camera = camera_dup(
				&window->render.scene.orig_camera,
				&window->render.scene.camera->controls);
		free(window->render.scene.camera);
		window->render.scene.camera = camera;
		render(window);
	}
	camera = window->render.scene.camera;
	camera->controls.moving += set_control(&camera->controls.zoom,
			&keydata, MLX_KEY_O, MLX_KEY_I);
	camera->controls.moving += set_control(&camera->controls.focus_dist,
			&keydata, MLX_KEY_J, MLX_KEY_K);
	movement_event(&keydata, window->render.scene.camera);
	configure_sky_box(&window->render.scene);
}
