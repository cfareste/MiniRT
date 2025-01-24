/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition_lights_helpers_bonus.h                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:35:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "composer/composer_bonus.h"

int	fill_ambient(t_composer *composer, t_light *ambiental, char **buffer);

int	fill_lights(t_composer *composer, t_light *lights, char **buffer);
