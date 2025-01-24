/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_job_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:11:02 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"
#include "../../job_bonus.h"
#include "window/window_bonus.h"
#include <stdlib.h>

static	void	destroy(t_job *job)
{
	free(job);
}

static	void	free_job(t_job *job)
{
	job->destroy(job);
}

static int	run(t_job *job, t_window *window)
{
	(void) job;
	main_destroy(window);
	close_window(window);
	return (1);
}

t_job	*init_destroy_job(t_job *job)
{
	job->type = DESTROY_JOB;
	job->required = 1;
	job->run = run;
	job->free = free_job;
	job->destroy = destroy;
	return (job);
}
