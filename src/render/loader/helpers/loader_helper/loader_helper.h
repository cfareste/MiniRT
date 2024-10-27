/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:58 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:52:58 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "render/loader/loader.h"

void			add_loader_progress(t_loader *loader);

unsigned int	get_loader_progress(t_loader *loader);

void			set_loader_progress(t_loader *loader, unsigned int current);

unsigned int	get_loader_total(t_loader *loader);

void			set_loader_total(t_loader *loader, unsigned int total);
