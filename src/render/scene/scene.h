/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:46 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 17:33:30 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# define SCENE_FILE_EXTENSION ".rt"

# include "light/light.h"
# include "figure/figure.h"
# include "camera/camera.h"

typedef struct s_scene
{
	t_light		*ambient_light;
	t_camera	*camera;
	t_light		*lights;
	t_figure	*figures;
	char		*name;
}	t_scene;

void	parse_scene_from_file(t_scene *scene, char *filename);

void	check_scene(t_scene *scene);

void	print_scene(t_scene *scene);

#endif
