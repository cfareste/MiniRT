/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:16:20 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 21:08:03 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "destroy_job.h"
#include "window/window.h"
#include <stdlib.h>

static int run(t_job *job, t_window *window)
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
