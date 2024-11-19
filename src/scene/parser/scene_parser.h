/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:40:31 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 23:42:51 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../scene.h"

void	check_scene_parsing(t_parser_ctx *ctx, t_scene *scene);

int		try_parse_scene_elems(t_parser_ctx *ctx, char **scene_args,
			t_scene *scene);
