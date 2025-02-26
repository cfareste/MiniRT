/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:52:17 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "utils/utils.h"
#include "libft.h"

static int	run(t_job *job, t_window *window)
{
	(void) job;
	(void) window;
	return (1);
}

static void	destroy(t_job *job)
{
	job->free(job);
}

static void	free_job(t_job *job)
{
	free(job->arg);
	free(job);
}

t_job	*new_job(void)
{
	t_job	*job;

	job = ft_calloc(1, sizeof(t_job));
	if (!job)
		throw_sys_error("Mem doesn't like job allocating :( ");
	job->type = ANON_JOB;
	init_async_flag(&job->removed, 0);
	job->required = 0;
	job->free = free_job;
	job->destroy = destroy;
	job->run = run;
	job->to_free = 1;
	return (job);
}
