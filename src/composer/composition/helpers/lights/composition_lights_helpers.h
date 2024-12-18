/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition_lights_helpers.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:35:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/18 17:38:10 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "composer/composer.h"

int	fill_ambient(t_composer *composer, t_light *ambiental, char **buffer);

int	fill_lights(t_composer *composer, t_light *lights, char **buffer);
