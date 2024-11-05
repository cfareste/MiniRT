/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:40:31 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/05 22:47:21 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../scene.h"

void	parse_scene_from_file(t_scene *scene, char *filename);

void	parse_scene_from_str(t_scene *scene, char *str);
