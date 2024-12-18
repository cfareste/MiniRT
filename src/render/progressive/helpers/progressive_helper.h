/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressive_helper.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:59:52 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 17:00:35 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/render_bonus.h"

void	clean_progress(t_progressive progress[STRATEGIES_AMOUNT]);

void	restart_progress(t_progressive progress[STRATEGIES_AMOUNT],
			t_size *img_size, t_render *render);

void	reset_progress(t_progressive progress[STRATEGIES_AMOUNT],
			t_size *size, int parts_amount);
