/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_job_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:06:15 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/window_bonus.h"
#include "exporter/helpers/exporter_helper_bonus.h"
#include <stdlib.h>

static	void	destroy(t_job *job)
{
	t_export	*export;

	export = job->arg;
	destroy_image(export->image);
	free(export);
	job->free(job);
}

static	void	free_job(t_job *job)
{
	free(job);
}

static int	run(t_job *job, t_window *window)
{
	if (is_exporter_active(&window->exporter))
		return (0);
	set_exporter_active(&window->exporter, 1);
	exec_export(job->arg);
	return (1);
}

t_job	*init_export_job(t_job *job, t_export *export)
{
	job->type = EXPORT_JOB;
	job->arg = export;
	job->required = 0;
	job->run = run;
	job->free = free_job;
	job->destroy = destroy;
	return (job);
}
