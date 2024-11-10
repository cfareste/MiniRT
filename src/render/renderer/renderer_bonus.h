/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 14:10:52 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "window/window.h"
#include "render/render_bonus.h"
#include <pthread.h>

void	render(t_window *window_);

void	stop_render(t_render *render);
