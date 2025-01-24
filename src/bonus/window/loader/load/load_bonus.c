/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:11:06 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 18:19:32 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "load_bonus.h"
#include "utils/utils_bonus.h"
#include "../helpers/loader_helper_bonus.h"
#include "window/jobs/job/types/image_resize/image_resize_job_bonus.h"
#include "window/jobs/job/helpers/job_helper_bonus.h"
#include "../strategies/strategies_bonus.h"
#include "../loader_bonus.h"

static void	paint(t_load *load)
{
	if (!loader_is_alive(load->loader))
		return ;
	if (loader_to_resize(load->loader))
	{
		loader_update_size(load->loader);
		wait_job(push_job(load->loader->jobs,
				init_img_resize_job(new_job(),
					load->loader->size, load->loader->image,
					&load->loader->img_mutex)),
			(int (*)(void *)) loader_is_alive, load->loader);
		loader_set_resize(load->loader, 0);
	}
	if (load->loader->mode == BAR && loader_is_alive(load->loader))
		paint_bar(load->loader, get_image_size(load->loader->image,
				&load->loader->img_mutex));
	else if (loader_is_alive(load->loader))
		paint_text(load->loader, get_image_size(load->loader->image,
				&load->loader->img_mutex));
}

void	clean_load(t_loader *loader)
{
	t_size		img_size;
	int			max;
	uint32_t	i;
	uint32_t	j;

	img_size = get_image_size(loader->image, &loader->img_mutex);
	max = img_size.width * img_size.height;
	i = 0;
	pthread_mutex_lock(&loader->img_mutex);
	while (i < img_size.width)
	{
		j = 0;
		while (j < img_size.height)
		{
			mlx_put_pixel(loader->image, i, j, 0);
			j++;
		}
		i++;
	}
	pthread_mutex_unlock(&loader->img_mutex);
}

void	*minirt_load_routine(t_load *load)
{
	int	i;

	if (!loader_is_alive(load->loader))
		return (free(load), NULL);
	pthread_mutex_lock(&load->loader->progress.mutex);
	load->loader->progress.current = 0;
	load->loader->progress.total = 0;
	pthread_mutex_unlock(&load->loader->progress.mutex);
	clean_load(load->loader);
	i = 0;
	while (loader_is_alive(load->loader))
	{
		paint(load);
		if (loader_is_alive(load->loader) && i == 0)
			loader_set_img_enabled(load->loader, 1);
		i++;
	}
	free(load);
	return (NULL);
}

t_load	*new_loader_load(t_loader *loader)
{
	t_load	*load;

	load = ft_calloc(1, sizeof(t_load));
	if (!load)
		throw_sys_error("allocing new loader");
	load->loader = loader;
	return (load);
}
