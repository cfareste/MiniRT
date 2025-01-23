/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:13:56 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 18:22:58 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/jobs/job/job.h"
#include "utils/async_flag/async_flag.h"

void	wait_job(t_job *job, int (*check_proceed)(void *arg), void *arg)
{
	int	removed;

	removed = get_async_flag(&job->removed);
	while (!removed
		&& ((check_proceed && check_proceed(arg)) || !check_proceed))
		removed = get_async_flag(&job->removed);
	if (removed)
		job->free(job);
}
