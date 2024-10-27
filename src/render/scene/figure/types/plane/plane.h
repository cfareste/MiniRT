/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:40 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:54:40 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# define PLANE_ID "pl"

# include "render/utils/coordinates/coordinates.h"
# include "render/scene/figure/figure.h"

typedef struct s_plane_attrs
{
	t_vector	orientation;
}	t_plane_attrs;

typedef struct s_figure	t_figure;

t_figure	*new_plane(char **parts);

void		set_plane(t_figure *plane, t_point *position, t_plane_attrs *attrs);

#endif
