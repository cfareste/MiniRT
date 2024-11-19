/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:43 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 19:22:48 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define EXPORT_BASE_DIR "assets/exports/"
#include "render/render_bonus.h"
#include "window/jobs/jobs.h"

typedef struct s_exporter
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
	int				active;
	t_render		*render;
	t_jobs			*jobs;
}	t_exporter;

void	export_image(t_exporter *exporter, t_jobs *jobs);

void	init_exporter(t_exporter *exporter, t_render *render, t_jobs *jobs);
