/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_progress_helper.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:05:38 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/27 17:16:23 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../../loader_bonus.h"

double	get_progress_factor(t_progress *progress);

void	loader_set_total(t_loader *loader, int total);

void	loader_add_progress(t_loader *loader);
