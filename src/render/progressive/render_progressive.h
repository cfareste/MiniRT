/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_progressive.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:40:39 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/17 17:24:46 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils/size/size.h"
#include "render/utils/color/color.h"

typedef struct s_progressive
{
	unsigned long	i;
	t_size			size;
	t_color			*colors;
}	t_progressive;

void	init_progressive(t_progressive *prog, t_size size);
