/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:13:25 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/29 21:14:37 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../job.h"

void	wait_job(t_job *job, int (*check_proceed)(void *arg), void *arg);

void	job_set_to_free(t_job *job, int to_free);