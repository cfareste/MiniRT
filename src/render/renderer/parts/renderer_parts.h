/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_parts.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:48:10 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:26 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../render.h"

void	render_parts(t_render *render, t_strategy strategy, uint64_t *seed);

void	set_parts(t_render *render);

void	update_parts(t_render *render, t_size *img_size);

void	join_parts(t_render_part *parts, int amount, t_rend_prog *progress);
