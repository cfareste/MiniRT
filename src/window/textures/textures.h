/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:28:21 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 21:53:58 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "texture/texture.h"
#include "window/loader/loader_bonus.h"
#include "window/jobs/jobs.h"

typedef struct s_textures
{
	int			amount;
	t_texture	*texture;
}	t_textures;

t_texture	*get_texture(t_textures *textures, char *path);

void		free_textures(t_textures *textures);

void		load_textures(t_textures *textures, t_jobs *jobs);
