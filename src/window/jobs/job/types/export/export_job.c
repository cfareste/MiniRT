/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:06:15 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/11 00:54:48 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export_job.h"
#include "window/window.h"
#include "exporter/helpers/exporter_helper_bonus.h"
#include <stdlib.h>

#include "libft.h"

static	void	free_job(t_job *job)
{
	ft_printf("FREEEING\n");
	free(job);
}

static int	run(t_job *job, t_window *window)
{
	if (is_exporter_active(job->arg))
		return (0);
	export_image(job->arg, &window->jobs, 1);
	return (1);
}

t_job	*init_export_job(t_job *job, t_exporter *exporter)
{
	job->type = EXPORT_JOB;
	job->arg = exporter;
	job->required = 1;
	job->run = run;
	job->free = free_job;
	return (job);
}
