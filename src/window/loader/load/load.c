/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:11:06 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/27 17:14:36 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "load.h"
#include "utils/utils_bonus.h"
#include "../helpers/loader_helper.h"
#include "window/jobs/job/types/image_resize/image_resize_job.h"
#include "../strategies/strategies.h"

static void	paint(t_load *load)
{
	t_size		img_size;

	if (!loader_is_alive(load->loader))
		return ;
	if (1 || load->loader->resize)
	{
		loader_update_size(load->loader);
		wait_job(push_job(load->loader->jobs,
				init_img_resize_job(new_job(),
					load->loader->size, load->loader->image)));
		printf("YES Loader resizing\n");
	}
	else
		printf("NO Loader resizing\n");
	load->loader->resize = 0;
	if (!loader_is_alive(load->loader))
		return ;
	img_size = get_image_size(load->loader->image, &load->loader->img_mutex);
	if (!loader_is_alive(load->loader))
		return ;
	if (load->loader->mode == BAR)
		paint_bar(load->loader, img_size);
	else
		paint_text(load->loader, img_size);
	printf("Salgo paint\n");
}

static void	clean_image(t_loader *loader)
{
	t_size		img_size;
	int			max;
	int			i;

	img_size = get_image_size(loader->image, &loader->img_mutex);
	max = img_size.width * img_size.height * 4;
	pthread_mutex_lock(&loader->progress.mutex);
	loader->progress.current = 0;
	loader->progress.total = 0;
	pthread_mutex_unlock(&loader->progress.mutex);
	i = 0;
	pthread_mutex_lock(&loader->img_mutex);
	while (i < max)
		loader->image->pixels[i++] = 0;
	pthread_mutex_unlock(&loader->img_mutex);
}

void	*minirt_load_routine(t_load *load)
{
	int	i;

	if (!loader_is_alive(load->loader))
		return (NULL);
	clean_image(load->loader);
	i = 0;
	while (loader_is_alive(load->loader))
	{
		paint(load);
		printf("Salgo paintroutine\n");
		if (loader_is_alive(load->loader) && i == 0)
			loader_set_img_enabled(load->loader, 1);
		i++;
	}
	printf("Salgo routine\n");
	return (NULL);
}

t_load	*new_loader_load(t_loader *loader)
{
	t_load	*load;

	load = ft_calloc(1, sizeof(t_load));
	if (!load)
		return (NULL);
	load->loader = loader;
	return (load);
}
