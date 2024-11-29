/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:18 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/25 17:19:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "../image/image_bonus.h"
#include "../exporter_bonus.h"
#include "window/loader/loader_bonus.h"

typedef struct s_export
{
	t_exporter	*exporter;
	t_image		*image;
}	t_export;

t_export	*new_export(t_exporter *exporter);

void		*export_routine(t_export *export);

void		exec_export(t_export *export);