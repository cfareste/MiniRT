/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition_figures_helpers_bonus.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:32:12 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MATERIAL_TITLE "mat:"
#define GLOSSINESS_TITLE "gl:"
#define PATTERN_TITLE "cd:"
#define BUMP_MAP_TITLE "bm:"

#include "composer/composer_bonus.h"

int	fill_figures(t_composer *composer, t_figure *figures, char **buffer);
