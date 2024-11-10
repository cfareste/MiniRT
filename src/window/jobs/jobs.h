/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:18:21 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 13:13:16 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "job/job.h"

typedef struct s_jobs
{
	int		amount;
	int		req_len;
	t_job	*job;
}	t_jobs;

void	push_job(t_jobs *jobs, t_job *job);

int		remove_job(t_jobs *jobs, t_job *job);

void	exec_jobs(t_jobs *jobs, mlx_t *mlx);
