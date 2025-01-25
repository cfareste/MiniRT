/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressive_helper.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:59:52 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:20 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/render.h"

void	clean_progress(t_rend_prog progress[STRATEGIES_AMOUNT]);

void	restart_progress(t_rend_prog progress[STRATEGIES_AMOUNT],
			t_size *img_size);

void	reset_progress(t_rend_prog progress[STRATEGIES_AMOUNT],
			t_size *size, int parts_amount);
