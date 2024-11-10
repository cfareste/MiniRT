/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anon_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:05:35 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 21:05:24 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anon_job.h"

t_job	*init_anon_job(t_job *job, int (*run)(t_job *, t_window *), void *arg)
{
	job->type = ANON_JOB;
	job->arg = arg;
	job->run = run;
	return (job);
}
