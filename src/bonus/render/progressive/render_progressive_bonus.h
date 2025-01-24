/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_progressive_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:40:39 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils/size/size_bonus.h"
#include "utils/iterators/iterators_bonus.h"
#include "render/utils/color/color_bonus.h"
#include "../renderer/parts/render_parts_amount_bonus.h"
#include "../renderer/renderer_args_bonus.h"

typedef struct s_render_part	t_render_part;
typedef struct s_render			t_render;

typedef struct s_rend_prog
{
	t_color			*colors;
	t_iterators		iter[PARTS_AMOUNT];
}	t_rend_prog;

void	init_progressive(t_rend_prog *prog, t_size *size);

void	reset_progress(t_rend_prog *prog, t_size *size, int parts_amount);

void	render_prog_pixel(t_render_part *part, t_iterators *iter,
			uint64_t *seed);

void	render_prog_parts(t_render_args *args, t_render *render, uint64_t *seed);