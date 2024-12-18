/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_parts.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:48:10 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 17:08:13 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../render_bonus.h"

void			render_parts(t_render *render, t_size *img_size,
					uint32_t *seed, int persist);

void			destroy_parts(t_render_part *parts, int amount);

t_render_part	*fill_parts(t_render *render, t_size *img_size);
