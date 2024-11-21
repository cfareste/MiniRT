/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:45 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/21 19:49:11 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exporter_bonus.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include "render/helpers/render_helper_bonus.h"
#include "image/image_bonus.h"
#include "helpers/exporter_helper_bonus.h"
#include "window/jobs/job/types/export/export_job.h"
#include "export/export.h"
#include <limits.h>

void	export_image(t_exporter *exporter, t_jobs *jobs)
{
	if (!is_render_finished(exporter->render))
		return ;
	push_job(jobs, init_export_job(new_job(), new_export(exporter)));
}

void	init_exporter(t_exporter *exporter, t_render *render, t_jobs *jobs)
{
	pthread_mutex_init(&exporter->mutex, NULL);
	exporter->render = render;
	exporter->jobs = jobs;
}

void	destroy_exporter(t_exporter *exporter)
{
	set_exporter_active(exporter, 0);
	pthread_join(exporter->thread, NULL);
}
