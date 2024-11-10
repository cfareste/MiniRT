/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:28:21 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 19:53:26 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "texture/texture.h"
#include "loader/multi_loader_bonus.h"
#include "window/jobs/jobs.h"

typedef struct s_textures
{
	int			amount;
	t_texture	*texture;
}	t_textures;

t_texture	*get_texture(t_textures *textures, char *path);

void		free_textures(t_textures *textures);

void		load_textures(t_multi_loader *loader, t_textures *textures,
				t_jobs *jobs);
