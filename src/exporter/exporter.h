/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:43 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:52:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define EXPORT_BASE_DIR "exports/"
#include "render/render.h"
#include "window/jobs/jobs.h"
#include "window/loader/loader.h"

typedef struct s_exporter
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
	int				active;
	t_render		*render;
	t_jobs			*jobs;
	t_loader		*loader;
}	t_exporter;

void	export_image(t_exporter *exporter, t_jobs *jobs);

void	init_exporter(t_exporter *exporter, t_render *render, t_jobs *jobs,
			t_loader *loader);

void	destroy_exporter(t_exporter *exporter);
