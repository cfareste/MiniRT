/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/30 21:56:11 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	create_renderers(t_render *render)
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

void	*render_routine(t_render *render)
{
	t_size	size;

	set_render_finish(render, 0);
	if (is_render_finished(render) || !render->image)
		return (NULL);
	size = get_image_size(render->image, &render->image_mutex);
	set_loader_total(&render->loader,
		size.width * size.height);
	create_renderers(render);
	if (is_render_finished(render))
		return (NULL);
	pthread_mutex_lock(&render->image_mutex);
	render->image->instances[0].enabled = true;
	pthread_mutex_unlock(&render->image_mutex);
	set_loader_visibility(&render->loader, false);
	pthread_mutex_lock(&render->mutex);
	printf("FINISHED RENDER: %f\n\n", mlx_get_time() - render->start_time);
	pthread_mutex_unlock(&render->mutex);
	return (NULL);
}

void	render(t_render *render, mlx_t *mlx)
{
	ft_printf("RENDERING\n");
	stop_render(render);
	pthread_mutex_lock(&render->loader.image_mutex);
	mlx_resize_image(render->loader.image, mlx->width, mlx->height);
	pthread_mutex_unlock(&render->loader.image_mutex);
	set_loader_visibility(&render->loader, true);
	pthread_mutex_lock(&render->image_mutex);
	render->image->instances[0].enabled = false;
	mlx_resize_image(render->image, mlx->width, mlx->height);
	pthread_mutex_unlock(&render->image_mutex);
	pthread_mutex_lock(&render->mutex);
	render->start_time = mlx_get_time();
	pthread_mutex_unlock(&render->mutex);
	if (pthread_create(&render->thread, NULL,
			(void *(*)(void*)) render_routine, (void *) render))
		throw_sys_error("creating new render thread");
}
