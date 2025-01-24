/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:59:03 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 18:09:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "title_job.h"
#include "window/window.h"

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
