/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:58 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/26 14:24:31 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../camera.h"

void	parse_camera(t_parser_ctx *ctx, char **parts, t_camera **camera);
