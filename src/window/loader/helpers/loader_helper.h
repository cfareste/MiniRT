/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:09:17 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/29 17:57:27 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../loader_bonus.h"

int		loader_is_alive(t_loader *loader);

void	loader_set_alive(t_loader *loader, int alive);

void	loader_set_img_enabled(t_loader	*loader, int enabled);

int		loader_to_resize(t_loader *loader);

void	loader_set_resize(t_loader *loader, int resize);
