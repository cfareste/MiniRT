/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:59:14 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_BONUS_H
# define SPHERE_BONUS_H
# define SPHERE_ID "sp"

typedef struct s_sphere_attrs
{
	double	radius;
}	t_sphere_attrs;

typedef struct s_figure	t_figure;

t_figure	*new_sphere(t_point *pos, t_color *color, t_sphere_attrs *sp_attrs);

#endif
