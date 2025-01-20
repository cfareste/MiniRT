/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:11:02 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/20 19:40:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include "../../job.h"
#include "destroy_job.h"
#include "utils/size/size.h"
#include "window/jobs/job/helpers/job_helper.h"
#include "window/window.h"

static	void	destroy(t_job *job)
{
	pthread_mutex_destroy(&job->finished_mutex);
	pthread_mutex_destroy(&job->to_free_mutex);
	free(job);
}

static	void	free_job(t_job *job)
{
	if (!job->to_free)
		job_set_to_free(job, 1);
	else
		job->destroy(job);
}

static int	run(t_job *job, t_window *window)
{
	main_destroy(window);
	close_window(window);
	pthread_mutex_lock(&job->finished_mutex);
	job->finished = 1;
	pthread_mutex_unlock(&job->finished_mutex);
	return (1);
}

t_job	*init_destroy_job(t_job *job)
{
	pthread_mutex_init(&job->finished_mutex, NULL);
	pthread_mutex_init(&job->to_free_mutex, NULL);
	job->type = DESTROY_JOB;
	job->required = 1;
	job->run = run;
	job->free = free_job;
	job->destroy = destroy;
	return (job);
}
