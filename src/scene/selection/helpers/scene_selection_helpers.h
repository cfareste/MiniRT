/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_selection_helpers.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:06:28 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/15 17:12:48 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"

t_figure	*get_selection_fig(t_scene *scene);

void		set_selection_fig(t_scene *scene, t_figure *selection);
