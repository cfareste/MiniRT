/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_job_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:58:57 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../job_bonus.h"

typedef struct s_title_job_param
{
	char	*new_title;
}	t_title_job_param;

t_job	*init_title_job(t_job *job, char *param);