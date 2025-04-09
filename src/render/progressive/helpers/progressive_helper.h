/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressive_helper.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:59:52 by arcanava          #+#    #+#             */
/*   Updated: 2025/03/20 18:51:33 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/render.h"

void	clean_progress(t_rend_prog *progress);

void	restart_progress(t_rend_prog *progress,
			t_size *img_size);

void	reset_progress(t_rend_prog *progress,
			t_size *size, int parts_amount);
