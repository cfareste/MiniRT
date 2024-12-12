/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:58:17 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 14:45:16 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "scene/scene.h"
#include "scene/camera/camera.h"

void		change_figure_material(t_figure *selection);

t_figure	*change_figure_type(t_scene *scene, t_figure *old_figure);
