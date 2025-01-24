/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:11:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "libft.h"
#include "utils/utils.h"
#include "window/helpers/window_helper.h"

static void	*render_routine(t_render *render)
{
	t_window	*window;

	window = get_window(NULL);
	set_viewport(render->scene.camera,
		&render->scene.camera->viewport, window->size);
	render_parts(render);
	printf("Finished render in %.3f seconds\n\n",
		mlx_get_time() - render->start_time);
	return (NULL);
}

void	render(t_render *render)
{
	printf("RENDERING\n");
	render->start_time = mlx_get_time();
	render_routine(render);
}
