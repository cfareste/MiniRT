/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 00:18:59 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# define SPHERE_ID "sp"

typedef struct s_sphere_attrs
{
	double	radius;
}	t_sphere_attrs;

typedef struct s_figure	t_figure;

t_figure	*new_sphere(t_point *pos, t_color *color, t_sphere_attrs *sp_attrs);

#endif
