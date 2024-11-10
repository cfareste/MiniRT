/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:52:17 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 13:13:47 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "utils/utils_bonus.h"
#include "libft.h"
#include <pthread.h>

t_job	*new_job(t_job_type type, void *args, int required)
{
	t_job	*job;

	job = ft_calloc(1, sizeof(t_job));
	if (!job)
		throw_sys_error("Mem doesn't like job allocating :( ");
	job->type = type;
	job->args = args;
	job->required = required;
	job->prev = job;
	job->next = job;
	return (job);
}

void	exec_job(t_job *job, mlx_t *mlx)
{
	(void) mlx;
	printf("Executing %p requ: %d\n", job, job->required);
}
