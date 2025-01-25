/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:33:35 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:40 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "window/textures/textures.h"

static t_texture	*push_texture(t_textures *textures, char *filename)
{
	t_texture	*texture;

	texture = ft_calloc(1, sizeof(t_texture));
	if (!texture)
		throw_sys_error("allocating texture");
	texture->path = ft_strdup(filename);
	if (!texture->path)
		throw_sys_error("allocating texture path");
	texture->next = textures->texture;
	textures->texture = texture;
	textures->amount += 1;
	return (texture);
}

t_texture	*get_texture(t_textures *textures, char *path)
{
	t_texture	*texture;

	texture = textures->texture;
	while (texture && ft_strcmp(texture->path, path) != EQUAL_STRINGS)
		texture = texture->next;
	if (!texture)
		texture = push_texture(textures, path);
	return (texture);
}
