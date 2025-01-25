/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:09:17 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../loader.h"

int		loader_is_alive(t_loader *loader);

void	loader_set_alive(t_loader *loader, int alive);

void	loader_set_img_enabled(t_loader	*loader, int enabled);

int		loader_to_resize(t_loader *loader);

void	loader_set_resize(t_loader *loader, int resize);
