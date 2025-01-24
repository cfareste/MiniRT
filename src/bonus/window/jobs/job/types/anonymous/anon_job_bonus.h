/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anon_job_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:05:32 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../job_bonus.h"

t_job	*init_anon_job(t_job *job, int (*run)(t_job *, t_window *), void *arg);
