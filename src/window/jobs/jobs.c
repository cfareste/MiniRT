/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:18:23 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 15:29:51 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "utils/utils_bonus.h"
#include <stdlib.h>

#include "libft.h"

void	push_job(t_jobs *jobs, t_job *job)
{
	if (!job)
		throw_error("push_job: job is NULL");
	jobs->amount += 1;
	if (!jobs->job)
		jobs->job = job;
	else
		jobs->job->next = job;
}

int	remove_job(t_jobs *jobs, t_job	*job)
{
	t_job	*old;
	t_job	*prev;

	old = jobs->job;
	prev = NULL;
	if (!old)
		return (0);
	while (old->next)
	{
		prev = old;
		old = old->next;
	}
	ft_printf("Removing: %p / %d\n", job, jobs->amount);
	jobs->amount -= 1;
	if (prev)
		prev->next = old->next;
	else
		jobs->job = old->next;
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
	while (i < jobs->amount)
	{
		if (job->required
			|| (!jobs_executed && i == jobs->amount - 1))
		{
			jobs_executed++;
			job->run(job, window);
			if (remove_job(jobs, jobs->job))
			{
				job = jobs->job;
				continue ;
			}
		}
		i++;
		job = job->next;
	}
}
