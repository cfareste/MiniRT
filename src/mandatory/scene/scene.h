/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:46 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:52:23 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "light/light.h"
# include "figure/figure.h"
# include "camera/camera.h"

typedef struct s_scene
{
	t_light				*ambient_light;
	t_camera			*camera;
	t_light				*lights;
	t_figure			*figures;
}	t_scene;

#endif
