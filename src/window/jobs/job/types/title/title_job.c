/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:59:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/28 17:08:44 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "title_job.h"
#include "window/window.h"
#include "utils/utils_bonus.h"

static int	run(t_job *job, t_window *window)
{
	mlx_set_window_title(window->mlx, job->arg);
	return (1);
}

t_job	*init_title_job(t_job *job, char *arg)
{
	job->type = TITLE_JOB;
	job->arg = arg;
	job->run = run;
	job->required = 1;
	return (job);
}
