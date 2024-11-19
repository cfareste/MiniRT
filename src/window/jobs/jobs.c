/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:18:23 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 16:33:16 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "utils/utils_bonus.h"
#include <stdlib.h>

#include "libft.h"

void	push_job(t_jobs *jobs, t_job *job)
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
	old->free(old);
	return (1);
}

void	free_jobs(t_jobs *jobs)
{
	while (jobs->job)
		free(jobs->job++);
}

void	exec_jobs(t_jobs *jobs, t_window *window)
{
	int		i;
	int		jobs_executed;
	t_job	*job;

	job = jobs->job;
	i = 0;
	jobs_executed = 0;
	pthread_mutex_lock(&jobs->mutex);
	while (job && i < jobs->amount)
	{
		if (job->required
			|| (!jobs_executed && i == jobs->amount - 1))
		{
			jobs_executed++;
			if (job->run(job, window) && remove_job(jobs, job))
			{
				job = jobs->job;
				continue ;
			}
		}
		i++;
		job = job->next;
	}
	pthread_mutex_unlock(&jobs->mutex);
}

void	destroy_jobs(t_jobs *jobs)
{
	while (jobs->amount)
		remove_job(jobs, jobs->job);
}
