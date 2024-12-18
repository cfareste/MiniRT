/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition_figures_helpers.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:32:12 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/18 17:34:06 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MATERIAL_TITLE "mat:"
#define GLOSSINESS_TITLE "gl:"
#define PATTERN_TITLE "cd:"
#define BUMP_MAP_TITLE "bm:"

#include "composer/composer.h"

int	fill_figures(t_composer *composer, t_figure *figures, char **buffer);
