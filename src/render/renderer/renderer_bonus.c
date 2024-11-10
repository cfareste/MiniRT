/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 14:17:45 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include "window/window.h"
#include "window/helpers/window_helper_bonus.h"
#include "render/render_bonus.h"
#include "render/helpers/render_helper_bonus.h"
#include "render/loader/helpers/loader_helper/loader_helper_bonus.h"
#include <pthread.h>

void	stop_render(t_render *render)
{
	if (!render || !render->thread)
		return ;
	set_render_finish(render, 1);
	pthread_join(render->thread, NULL);
	set_loader_visibility(&render->loader, false);
}

static void	render_parts(t_render *render)
{
	int				i;
	t_size			img_size;
	t_render_part	*parts;

	img_size = get_image_size(render->image, &render->image_mutex);
	render->parts_amount = 10;
	parts = ft_calloc(render->parts_amount, sizeof(t_render_part));
	if (!parts)
		throw_sys_error("ft_calloc in rendering");
	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		add_loader_progress(&render->loader);
		parts[i].render = render;
		parts[i].img_size = img_size;
		parts[i].min_size.height = i;
		pthread_create(&parts[i].thread, NULL,
			(void *(*)(void *)) render_part, parts + i);
		i++;
	}
	i = -1;
	while (++i < render->parts_amount)
		if (parts[i].thread)
			pthread_join(parts[i].thread, NULL);
	free(parts);
}

void	*render_routine(t_window *window)
{
	t_size	size;

	set_render_finish(&window->render, 0);
	if (is_render_finished(&window->render) || !window->render.image)
		return (NULL);
	size = get_image_size(window->render.image, &window->render.image_mutex);
	set_loader_total(&window->render.loader,
		size.width * size.height);
	render_parts(&window->render);
	if (is_render_finished(&window->render))
		return (NULL);
	pthread_mutex_lock(&window->render.image_mutex);
	window->render.image->instances[0].enabled = true;
	pthread_mutex_unlock(&window->render.image_mutex);
	set_loader_progress(&window->render.loader, 0);
	set_loader_visibility(&window->render.loader, false);
	set_render_finish(&window->render, 1);
	pthread_mutex_lock(&window->render.mutex);
	printf("FINISHED RENDER: %f\n\n",
		mlx_get_time() - window->render.start_time);
	pthread_mutex_unlock(&window->render.mutex);
	return (NULL);
}

void	render(t_window *window_)
{
	t_window	*window;

	window = (t_window *) window_;
	ft_printf("RENDERING\n");
	stop_render(&window->render);
	pthread_mutex_lock(&window->render.loader.image_mutex);
	mlx_resize_image(window->render.loader.image, window->mlx->width,
		window->mlx->height);
	pthread_mutex_unlock(&window->render.loader.image_mutex);
	set_loader_progress(&window->render.loader, 0);
	set_loader_visibility(&window->render.loader, true);
	pthread_mutex_lock(&window->render.image_mutex);
	window->render.image->instances[0].enabled = false;
	mlx_resize_image(window->render.image,
		window->mlx->width, window->mlx->height);
	pthread_mutex_unlock(&window->render.image_mutex);
	pthread_mutex_lock(&window->render.mutex);
	window->render.start_time = mlx_get_time();
	pthread_mutex_unlock(&window->render.mutex);
	if (pthread_create(&window->render.thread, NULL,
			(void *(*)(void*)) render_routine, window))
		throw_sys_error("creating new render thread");
}
