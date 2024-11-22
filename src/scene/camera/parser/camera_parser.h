/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:58 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/22 00:40:05 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../camera.h"

void	parse_camera(t_parser_ctx *ctx, char **parts, t_camera **camera);

void	set_camera_vectors(t_camera *camera);