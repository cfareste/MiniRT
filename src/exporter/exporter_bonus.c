/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:45 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/18 18:56:40 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exporter_bonus.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include "render/helpers/render_helper_bonus.h"
#include "image/image_bonus.h"
#include "helpers/exporter_helper_bonus.h"
#include "render/loader/helpers/loader_helper/loader_helper_bonus.h"
#include "window/jobs/job/types/export/export_job.h"
#include "export/export.h"
#include <limits.h>

void	export_image(t_exporter *exporter, t_jobs *jobs)
{
	if (!is_render_finished(exporter->render))
		return ;
	if (!is_exporter_active(exporter))
		exec_export(new_export(exporter));
	else
		push_job(jobs, init_export_job(new_job(), new_export(exporter)));
}

void	init_exporter(t_exporter *exporter, t_render *render, t_jobs *jobs)
{
	pthread_mutex_init(&exporter->mutex, NULL);
	exporter->render = render;
	exporter->jobs = jobs;
}
