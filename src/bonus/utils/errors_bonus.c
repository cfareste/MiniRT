/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/window_bonus.h"
#include "window/helpers/window_helper_bonus.h"
#include "window/jobs/job/types/destroy/destroy_job_bonus.h"
#include "window/jobs/job/helpers/job_helper_bonus.h"
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
