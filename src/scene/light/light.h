/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 17:43:40 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "float.h"
# include "render/utils/color/color.h"
# include "render/utils/point/point.h"
# include "render/utils/coordinates/coordinates.h"

typedef enum e_light_types
{
	LIGHT_ID = 'l',
	LIGHT_ID_MANDATORY = 'L',
	AMBIENT_LIGHT_ID = 'A'
}	t_light_type;

typedef struct s_light
{
	t_light_type	type;
	t_point			position;
	double			brightness;
	struct s_light	*next;
	t_color			color;
}	t_light;

t_light	*new_light(t_light **lights);

void	free_lights(t_light *lights);

void	print_light(t_light *light);

#endif
