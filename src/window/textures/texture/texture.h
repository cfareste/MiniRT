/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:32:29 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 19:18:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"

typedef struct s_texture	t_texture;

typedef struct s_texture
{
	char			*path;
	mlx_texture_t	*mlx;
	xpm_t			*xpm;
	t_texture		*next;
}	t_texture;
