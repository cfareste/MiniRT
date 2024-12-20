/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:16:20 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/11 00:54:36 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "destroy_job.h"
#include "window/window.h"
#include <stdlib.h>

static int	run(t_job *job, t_window *window)
{
	(void) job;
	destroy(window);
	exit(EXIT_FAILURE);
	return (0);
}

t_job	*init_destroy_job(t_job *job)
{
	job->type = DESTROY_JOB;
	job->run = run;
	job->required = 1;
	return (job);
}
