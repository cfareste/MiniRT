/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:07:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/24 16:13:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define DISK_ID "di"

#include "render/utils/point/point.h"

typedef struct s_disk_attrs
{
	double		radius;
	t_vector	orientation;
}	t_disk_attrs;

typedef struct s_figure	t_figure;

t_figure	*parse_disk(t_parser_ctx *ctx, char **parts);
