/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:18:23 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs_bonus.h"

t_job	*push_job(t_jobs *jobs, t_job *job)
{
	t_job	*aux;

	pthread_mutex_lock(&jobs->mutex);
	jobs->amount++;
	aux = jobs->job;
	while (aux && aux->next)
		aux = aux->next;
	if (!aux)
		jobs->job = job;
	else
		aux->next = job;
	pthread_mutex_unlock(&jobs->mutex);
	return (job);
}

int	remove_job(t_jobs *jobs, t_job *job)
{
	t_job	*old;
	t_job	*prev;

	old = jobs->job;
	prev = NULL;
	while (old && old != job)
	{
		prev = old;
		old = old->next;
	}
	if (!old)
		return (0);
	if (prev)
		prev->next = old->next;
	else
		jobs->job = old->next;
	jobs->amount--;
	if (old->to_free)
		old->free(old);
	else
		set_async_flag(&old->removed, 1);
	return (1);
}

void	exec_jobs(t_jobs *jobs, t_window *window)
{
	int		jobs_executed;
	t_job	*job;

	jobs_executed = 0;
	pthread_mutex_lock(&jobs->mutex);
	job = jobs->job;
	while (job)
	{
		if (job->required)
		{
			jobs_executed++;
			if (job->run(job, window) && remove_job(jobs, job))
			{
				job = jobs->job;
				continue ;
			}
		}
		job = job->next;
	}
	if (!jobs_executed && jobs->job)
		if (jobs->job->run(jobs->job, window))
			remove_job(jobs, jobs->job);
	pthread_mutex_unlock(&jobs->mutex);
}

void	destroy_jobs(t_jobs *jobs)
{
	t_job	*job;
	t_job	*aux;

	pthread_mutex_lock(&jobs->mutex);
	job = jobs->job;
	while (job)
	{
		aux = job;
		job = job->next;
		aux->destroy(aux);
	}
	pthread_mutex_unlock(&jobs->mutex);
}
