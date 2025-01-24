/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_helper_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:13:25 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../job_bonus.h"

void	wait_job(t_job *job, int (*check_proceed)(void *arg), void *arg);
