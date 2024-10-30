/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/29 16:57:03 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "window/window.h"
#include "render/render_bonus.h"
#include <pthread.h>

void	render(t_render *render, mlx_t *mlx);

void	stop_render(t_render *render);
