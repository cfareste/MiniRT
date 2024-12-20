/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_job.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:06:08 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/18 13:31:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../job.h"
#include "exporter/export/export.h"

t_job	*init_export_job(t_job *job, t_export *exporter);