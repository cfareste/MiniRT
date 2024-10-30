/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:58 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/29 17:00:51 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "render/loader/loader_bonus.h"

void			add_loader_progress(t_loader *loader);

unsigned int	get_loader_progress(t_loader *loader);

void			set_loader_progress(t_loader *loader, unsigned int current);

unsigned int	get_loader_total(t_loader *loader);

void			set_loader_total(t_loader *loader, unsigned int total);
