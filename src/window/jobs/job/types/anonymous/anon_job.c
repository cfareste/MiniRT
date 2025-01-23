/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anon_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:05:35 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 18:20:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/jobs/job/job.h"

t_job	*init_anon_job(t_job *job, int (*run)(t_job *, t_window *), void *arg)
{
	job->type = ANON_JOB;
	job->arg = arg;
	job->run = run;
	return (job);
}
