/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:19:13 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/16 18:10:45 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/render_bonus.h"

void	compute_pathtracing(t_render *render, t_ray *ray, t_color *sample_color,
			uint64_t *seed);
