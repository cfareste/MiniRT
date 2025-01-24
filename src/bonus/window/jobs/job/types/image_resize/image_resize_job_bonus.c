/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_resize_job_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:51:12 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus_bonus.h"
#include "../../job_bonus.h"
#include "image_resize_job_bonus.h"
#include "utils/size/size_bonus.h"

static	void	destroy(t_job *job)
{
	free(job->arg);
	job->arg = NULL;
	free(job);
}

static	void	free_job(t_job *job)
{
	job->destroy(job);
}

static int	run(t_job *job, t_window *window)
{
	t_resize_wrapper	*resize;

	(void) window;
	resize = (t_resize_wrapper *) job->arg;
	if (resize->mutex)
		pthread_mutex_lock(resize->mutex);
	mlx_resize_image(resize->image, resize->nsize.width,
		resize->nsize.height);
	if (resize->mutex)
		pthread_mutex_unlock(resize->mutex);
	return (1);
}

static t_resize_wrapper	*wrap_resize(t_size	nsize, mlx_image_t *image,
			pthread_mutex_t *mutex)
{
	t_resize_wrapper	*wrapper;

	wrapper = ft_calloc(1, sizeof(t_resize_wrapper));
	if (!wrapper)
		throw_sys_error("Resizing wrapper creation");
	wrapper->nsize = nsize;
	wrapper->image = image;
	wrapper->mutex = mutex;
	return (wrapper);
}

t_job	*init_img_resize_job(t_job *job, t_size	nsize, mlx_image_t *image,
			pthread_mutex_t *mutex)
{
	job->type = IMG_RESIZE_JOB;
	job->arg = wrap_resize(nsize, image, mutex);
	job->required = 1;
	job->run = run;
	job->free = free_job;
	job->destroy = destroy;
	job->to_free = 0;
	return (job);
}
