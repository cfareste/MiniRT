/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anon_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:05:35 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 17:28:44 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anon_job.h"

t_job	*init_anon_job(t_job *job, void (*run)(t_job *, t_window *), void *arg)
{
	job->type = ANON_JOB;
	job->arg = arg;
	job->run = run;
	return (job);
}
