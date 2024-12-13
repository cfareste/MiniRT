/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/13 22:43:59 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/render_bonus.h"

int		is_render_finished(t_render *render);

void	set_render_finish(t_render *render, int value);

void	render_set_resize(t_render *render, int value);

int		render_get_resize(t_render *render);

int		get_render_update(t_render *render);

void	set_render_update(t_render *render, int update);

int		is_render_alive(t_render *render);

