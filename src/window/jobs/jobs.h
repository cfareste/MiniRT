/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:18:21 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/26 13:57:57 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "job/job.h"
#include <pthread.h>

typedef struct s_jobs
{
	int				amount;
	t_job			*job;
	pthread_mutex_t	mutex;
}	t_jobs;

t_job	*push_job(t_jobs *jobs, t_job *job);

int		remove_job(t_jobs *jobs, t_job *job);

void	exec_jobs(t_jobs *jobs, t_window *window);

void	destroy_jobs(t_jobs *jobs);
