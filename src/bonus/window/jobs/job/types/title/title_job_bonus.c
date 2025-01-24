/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_job_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:59:03 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "title_job_bonus.h"
#include "window/window_bonus.h"

static int	run(t_job *job, t_window *window)
{
	mlx_set_window_title(window->mlx, job->arg);
	return (1);
}

// TODO: Delete this function??? (Not called anywhere)
t_job	*init_title_job(t_job *job, char *arg)
{
	job->type = TITLE_JOB;
	job->arg = arg;
	job->run = run;
	job->required = 1;
	return (job);
}
