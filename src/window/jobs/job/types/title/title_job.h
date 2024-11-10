/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_job.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:58:57 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 14:38:19 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../job.h"

typedef struct s_title_job_param
{
	char	*new_title;
}	t_title_job_param;

t_job	*init_title_job(t_job *job, char *param);