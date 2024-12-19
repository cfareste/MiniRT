/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:13 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/19 21:17:54 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera_events.h"
#include "../helpers/camera_helper.h"
#include "render/renderer/renderer_bonus.h"
#include "render/helpers/render_helper_bonus.h"
#include "libft.h"

void	focus_camera_to_selection(t_camera *camera, t_figure *selection)
{
	t_point	pos;

	pos = selection->position;
	if (ft_strcmp(selection->type, CONE_ID) == EQUAL_STRINGS)
		translate_point(&pos, &selection->co_attrs->orientation,
			selection->co_attrs->height / 2.0, &pos);
	get_vector(&pos, &camera->position, &camera->front);
	get_axes(&camera->front, &camera->right, &camera->up);
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
		set_async_flag(&window->render.update, 1);
	}
}
