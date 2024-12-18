/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_helpers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:23:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/18 17:30:38 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define SAMPLES_TITLE "samples:"
#define MAX_DEPTH_TITLE "max_depth:"
#define SOFT_SHADOWS_TITLE "soft_shadows:"
#define SCENE_NAME_TITLE "name:"
#define SKY_TITLE "sky:"
#define SKY_BOX_TITLE "sky_box:"
#define WIN_WIDTH_TITLE "width:"
#define WIN_HEIGHT_TITLE "height:"

#include "composer/composer.h"

int	fill_render(t_composer *composer, t_render *render, char **buffer);

int	fill_scene(t_composer *composer, t_scene *scene, char **buffer);

int	fill_window(t_composer *composer, t_render *render, char **buffer);

int	fill_camera(t_composer *composer, t_camera *camera, char **buffer);
