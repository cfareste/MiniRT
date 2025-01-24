/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_helpers_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:13:56 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure_bonus.h"

void	set_box_faces(t_box_attrs *attrs, t_point *box_pos);

int		get_face_index(t_figure *box, t_point *point);
