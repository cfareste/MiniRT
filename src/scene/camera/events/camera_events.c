/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:13 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_events.h"
#include "utils/utils.h"
#include "render/renderer/renderer.h"
#include "libft.h"

void	focus_camera_to_selection(t_camera *camera, t_figure *selection,
			t_size img_size)
{
	t_point	pos;

	pos = selection->position;
	if (ft_strcmp(selection->type, CONE_ID) == EQUAL_STRINGS)
		translate_point(&pos, &selection->co_attrs->orientation,
			selection->co_attrs->height / 2.0, &pos);
	get_vector(&pos, &camera->position, &camera->front);
	get_axes(&camera->front, &camera->right, &camera->up);
	set_viewport(camera, &camera->viewport, img_size);
}

void	camera_key_events(mlx_key_data_t *keydata, t_window *window)
{
	t_camera	*camera;

	if (keydata->modifier > MLX_SHIFT)
		return ;
	if (!get_async_flag(&window->render.blocked)
		&& keydata->action == MLX_PRESS && keydata->key == MLX_KEY_C)
	{
		stop_render(&window->render);
		camera = camera_dup(&window->render.scene.orig_camera);
		free(window->render.scene.camera);
		window->render.scene.camera = camera;
		set_viewport(camera, &camera->viewport,
			get_image_size(window->render.image, &window->render.image_mutex));
		set_async_flag(&window->render.update, 1);
	}
}
