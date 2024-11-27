/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_resize_job.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:51:12 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/27 18:40:52 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "image_resize_job.h"
#include "utils/size/size.h"

static	void	destroy(t_job *job)
{
	job->free(job);
}

static	void	free_job(t_job *job)
{
	free(job->arg);
	pthread_mutex_destroy(&job->finish_mutex);
	free(job);
}

static int	run(t_job *job, t_window *window)
{
	t_resize_wrapper	*resize;

	(void) window;
	resize = (t_resize_wrapper *) job->arg;
	mlx_resize_image(resize->image, resize->nsize.width,
		resize->nsize.height);
	pthread_mutex_unlock(&job->finish_mutex);
	return (1);
}

static t_resize_wrapper	*wrap_resize(t_size	nsize, mlx_image_t *image)
{
	t_resize_wrapper	*wrapper;

	wrapper = ft_calloc(1, sizeof(t_resize_wrapper));
	if (!wrapper)
		throw_sys_error("Resizing wrapper creation");
	wrapper->nsize = nsize;
	wrapper->image = image;
	return (wrapper);
}

t_job	*init_img_resize_job(t_job *job, t_size	nsize, mlx_image_t *image)
{
	pthread_mutex_init(&job->finish_mutex, NULL);
	pthread_mutex_lock(&job->finish_mutex);
	job->type = EXPORT_JOB;
	job->arg = wrap_resize(nsize, image);
	job->required = 1;
	job->run = run;
	job->free = free_job;
	job->destroy = destroy;
	return (job);
}
