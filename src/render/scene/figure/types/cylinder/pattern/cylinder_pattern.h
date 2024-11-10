/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_pattern.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:00:08 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 21:00:33 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/scene/figure/figure.h"

void	get_cylinder_body_pattern(t_figure *figure, t_point *point,
			t_color *res);
