/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:18 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:52:36 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../image/image.h"
#include "../exporter.h"

typedef struct s_export
{
	t_exporter	*exporter;
	t_image		*image;
}	t_export;

t_export	*new_export(t_exporter *exporter);

void		*export_routine(t_export *export);

void		exec_export(t_export *export);
