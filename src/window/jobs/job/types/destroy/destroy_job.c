/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:11:02 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 18:18:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "../../job.h"
#include "window/window.h"
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
