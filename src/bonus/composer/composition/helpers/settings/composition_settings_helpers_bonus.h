/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition_settings_helpers_bonus.h               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:23:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define SAMPLES_TITLE "samples:"
#define MAX_DEPTH_TITLE "max_depth:"
#define ANTIALIASING_TITLE "antialiasing:"
#define SOFT_SHADOWS_TITLE "soft_shadows:"
#define SCENE_NAME_TITLE "name:"
#define SKY_TITLE "sky:"
#define SKY_BOX_TITLE "sky_box:"
#define WIN_WIDTH_TITLE "width:"
#define WIN_HEIGHT_TITLE "height:"

#include "composer/composer_bonus.h"

int	fill_render(t_composer *composer, t_render *render, char **buffer);

int	fill_scene(t_composer *composer, t_scene *scene, char **buffer);

int	fill_window(t_composer *composer, t_render *render, char **buffer);

int	fill_camera(t_composer *composer, t_camera *camera, char **buffer);
