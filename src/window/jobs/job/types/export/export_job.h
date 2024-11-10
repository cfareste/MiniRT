/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_job.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:06:08 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 21:16:33 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../job.h"
#include "exporter/exporter_bonus.h"

t_job	*init_export_job(t_job *job, t_exporter *exporter);