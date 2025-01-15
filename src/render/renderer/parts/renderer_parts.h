/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_parts.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:48:10 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/15 13:16:50 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../render_bonus.h"

void	render_parts(t_render *render, uint32_t *seed, t_strategy strategy);

void	set_parts(t_render *render);

void	update_parts(t_render *render, t_size *img_size);

void	join_parts(t_render_part *parts, int amount, t_rend_prog *progress);