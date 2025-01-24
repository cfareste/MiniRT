/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anon_job_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:05:35 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/jobs/job/job_bonus.h"

t_job	*init_anon_job(t_job *job, int (*run)(t_job *, t_window *), void *arg)
{
	job->type = ANON_JOB;
	job->arg = arg;
	job->run = run;
	return (job);
}
