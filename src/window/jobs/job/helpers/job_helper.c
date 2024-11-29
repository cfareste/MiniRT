/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:13:56 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/29 21:16:18 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_helper.h"

void	wait_job(t_job *job, int (*check_proceed)(void *arg), void *arg)
{
	pthread_mutex_lock(&job->finished_mutex);
	while (!job->finished && check_proceed(arg))
	{
		pthread_mutex_unlock(&job->finished_mutex);
		pthread_mutex_lock(&job->finished_mutex);
	}
	pthread_mutex_unlock(&job->finished_mutex);
	job->free(job);
}

void	job_set_to_free(t_job *job, int to_free)
{
	pthread_mutex_lock(&job->to_free_mutex);
	job->to_free = to_free;
	pthread_mutex_unlock(&job->to_free_mutex);
}
