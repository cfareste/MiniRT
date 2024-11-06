/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/06 22:52:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "window/window.h"
#include "render/render_bonus.h"
#include <pthread.h>

void	render(t_render *render, mlx_t *mlx);

void	stop_render(t_render *render);
