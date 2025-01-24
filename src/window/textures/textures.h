/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:28:21 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 17:20:10 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "texture/texture.h"

typedef struct s_textures
{
	int			amount;
	t_texture	*texture;
}	t_textures;

t_texture	*get_texture(t_textures *textures, char *path);

void		free_textures(t_textures *textures);

void		load_textures(t_textures *textures);
