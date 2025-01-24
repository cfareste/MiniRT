/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_bonus_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:45 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exporter_bonus_bonus.h"
#include "helpers/exporter_helper_bonus_bonus.h"
#include "window/jobs/job/types/export/export_job_bonus.h"

void	export_image(t_exporter *exporter, t_jobs *jobs)
{
	push_job(jobs, init_export_job(new_job(), new_export(exporter)));
}

void	init_exporter(t_exporter *exporter, t_render *render, t_jobs *jobs,
			t_loader *loader)
{
	pthread_mutex_init(&exporter->mutex, NULL);
	exporter->render = render;
	exporter->jobs = jobs;
	exporter->loader = loader;
}

void	destroy_exporter(t_exporter *exporter)
{
	set_exporter_active(exporter, 0);
	if (exporter->thread)
		pthread_join(exporter->thread, NULL);
	exporter->thread = 0;
}
