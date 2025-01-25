/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_progress_helper.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:05:38 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:38 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../../loader.h"

double	get_progress_factor(t_progress *progress);

void	loader_set_total(t_loader *loader, int total);

void	loader_add_progress(t_loader *loader);
