/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:52:17 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 16:39:48 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "utils/utils_bonus.h"
#include "libft.h"
#include <pthread.h>

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
	job->required = 0;
	job->free = free_job;
	job->destroy = destroy;
	return (job);
}
