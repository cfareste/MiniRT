/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:52 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:28:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "./size/size.h"
#include "render/utils/color/color.h"

#define SEP 9

int		correct_file_extension(char *filename, char *extension);

void	throw_sys_error(char *msg);

char	*get_file_name(char *filename, char *extension);

char	*set_file_name(char *filename, char *extension,
			char *path, int version);

char	*colortoa(t_color *color);

char	*coordtoa(t_coordinates *coords, int precision);

void	join_format_str(char **buffer, char *prefix, char *str, char separator);
