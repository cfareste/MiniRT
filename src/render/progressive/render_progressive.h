/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_progressive.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:40:39 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 17:41:04 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils/size/size.h"
#include "render/utils/color/color.h"
#include "../strategies/strategy.h"

typedef struct s_render_part	t_render_part;

typedef struct s_progressive
{
	t_color			*colors;
	t_render_part	*parts;
}	t_progressive;

void	init_progressive(t_progressive *prog,
			t_size *size, t_render_part *parts);

void	reset_progress(t_progressive *prog, t_size *size, int parts_amount);
