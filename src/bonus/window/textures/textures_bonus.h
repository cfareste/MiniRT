/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:28:21 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "texture/texture_bonus.h"

typedef struct s_textures
{
	int			amount;
	t_texture	*texture;
}	t_textures;

t_texture	*get_texture(t_textures *textures, char *path);

void		free_textures(t_textures *textures);

void		load_textures(t_textures *textures);
