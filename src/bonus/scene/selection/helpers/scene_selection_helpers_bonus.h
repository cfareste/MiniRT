/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_selection_helpers_bonus.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:06:28 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/scene_bonus.h"

t_figure	*get_selection_fig(t_scene *scene);

void		set_selection_fig(t_scene *scene, t_figure *selection);
