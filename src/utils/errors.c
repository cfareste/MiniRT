/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/20 19:40:33 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "window/window.h"
#include "libft.h"
#include "window/helpers/window_helper_bonus.h"
#include "window/jobs/job/types/destroy/destroy_job.h"
#include "window/jobs/job/helpers/job_helper.h"
#include <string.h>
#include <errno.h>

void	throw_error(char *msg)
{
	ft_printff(STDERR_FILENO, "%s: %s\n",
		PROGRAM_NAME, msg);
	exit(EXIT_FAILURE);
}

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
