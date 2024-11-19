/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:40:31 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 12:38:02 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../scene.h"
#include "window/jobs/jobs.h"
#include "window/textures/textures.h"

void	parse_scene(t_scene *scene, t_textures *textures, char *filename);
