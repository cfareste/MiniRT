/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:27:17 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 01:56:57 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../composer.h"

#define SAMPLES_TITLE "samples:"
#define MAX_DEPTH_TITLE "max_depth:"
#define SOFT_SHADOWS_TITLE "soft_shadows:"
#define SCENE_NAME_TITLE "name:"
#define SKY_TITLE "sky:"
#define SKY_BOX_TITLE "sky_box:"
#define WIN_WIDTH_TITLE "width:"
#define WIN_HEIGHT_TITLE "height:"
#define GLOSSINESS_TITLE "gl:"
#define COLOR_DISRUPTION_TITLE "cd:"
#define BUMP_MAP_TITLE "bm:"

typedef struct s_composition
{
	t_composer	*composer;

	int			create_new_file;
}	t_composition;

void	*composition_routine(t_composition *composition);
