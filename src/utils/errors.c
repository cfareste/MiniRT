/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:34 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/window.h"
#include "window/helpers/window_helper.h"
#include "window/jobs/job/types/destroy/destroy_job.h"
#include "window/jobs/job/helpers/job_helper.h"
#include <stdio.h>
#include <stdlib.h>

void	throw_sys_error(char *msg)
{
	t_window	*window;

	window = get_window(NULL);
	if (window->mlx)
		wait_job(push_job(&window->jobs, init_destroy_job(new_job())),
			NULL, NULL);
	perror(msg);
	exit(EXIT_FAILURE);
}
