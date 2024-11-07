/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/06 19:23:24 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/scene/figure/figure.h"
#include "render/render_bonus.h"

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure);

int		is_render_finished(t_render *render);

void	set_render_finish(t_render *render, int value);

void	check_shadow_hits(t_figure **figure, t_hit_record *hit_record,
			t_ray *shadow_ray);

void	check_lights(t_hit_record *hit_record, t_scene *scene, t_color *color);
