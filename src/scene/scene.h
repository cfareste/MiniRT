/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:46 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/06 21:23:33 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "light/light.h"
# include "figure/figure.h"
# include "camera/camera.h"
# include "settings/scene_settings.h"

typedef struct s_scene
{
	t_scene_settings	settings;
	t_light				*ambient_light;
	t_camera			*camera;
	t_camera			orig_camera;
	t_light				*lights;
	t_figure			*figures;
	int					ready;
	pthread_mutex_t		mutex;
	t_figure			*selection;
	pthread_mutex_t		selection_mutex;
}	t_scene;

void	print_scene(t_scene *scene);

#endif
