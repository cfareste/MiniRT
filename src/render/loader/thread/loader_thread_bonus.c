/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_thread_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/09 22:08:32 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../helpers/bar_helper/bar_helper.h"
#include "../helpers/loader_helper/loader_helper_bonus.h"
#include "window/helpers/window_helper_bonus.h"
#include "utils/utils_bonus.h"

void	update_progress_bar(t_loader *loader, int bar_width, t_size img)
{
	t_size			bar;
	unsigned int	i;
	unsigned int	j;
	int				loading;

	bar.width = get_bar_total_width(img.width);
	bar.height = get_bar_height(img.height);
	loading = is_image_enabled(loader->image, &loader->image_mutex);
	i = img.width / 2 - bar.width / 2;
	while (loading
		&& i < (img.width / 2 - bar.width / 2) + bar_width)
	{
		j = (img.height / 2 - bar.height / 2);
		while (loading && j < (img.height / 2 - bar.height / 2) + bar.height)
		{
			pthread_mutex_lock(&loader->image_mutex);
			loading = is_image_enabled(loader->image, NULL);
			if (loading
				&& i < loader->image->width && j < loader->image->height)
				mlx_put_pixel(loader->image, i, j, 0xffffffff);
			pthread_mutex_unlock(&loader->image_mutex);
			j++;
		}
		i++;
	}
}

static int	is_loader_thread_alive(t_loader *loader)
{
	int	alive;

	pthread_mutex_lock(&loader->thread_finish_mutex);
	alive = !loader->thread_finished;
	pthread_mutex_unlock(&loader->thread_finish_mutex);
	return (alive);
}

void	*loader_routine(t_loader *loader)
{
	unsigned int	current;
	unsigned int	current_pre;
	t_size			img_size;
	t_size			img_size_pre;

	current = 101;
	img_size = get_image_size(loader->image, &loader->image_mutex);
	while (is_loader_thread_alive(loader))
	{
		img_size_pre = img_size;
		img_size = get_image_size(loader->image, &loader->image_mutex);
		current_pre = current;
		current = get_bar_width(img_size.width, get_loader_progress(loader),
				get_loader_total(loader));
		if (diff_sizes(&img_size, &img_size_pre)
			|| (current != current_pre && current == 0))
			paint_black_image(loader->image, &loader->image_mutex);
		if (current > current_pre)
			update_progress_bar(loader, current, img_size);
	}
	set_loader_visibility(loader, false);
	return (NULL);
}

void	kill_loader_routine(t_loader *loader)
{
	pthread_mutex_lock(&loader->thread_finish_mutex);
	loader->thread_finished = 1;
	pthread_mutex_unlock(&loader->thread_finish_mutex);
}
