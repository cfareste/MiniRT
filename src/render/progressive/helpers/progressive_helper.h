/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressive_helper.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:59:52 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/15 17:54:23 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/render_bonus.h"

void	clean_progress(t_rend_prog progress[STRATEGIES_AMOUNT]);

void	restart_progress(t_rend_prog progress[STRATEGIES_AMOUNT],
			t_size *img_size);

void	reset_progress(t_rend_prog progress[STRATEGIES_AMOUNT],
			t_size *size, int parts_amount);
