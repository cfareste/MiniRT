/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 12:55:56 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# define SPHERE_ID "sp"

typedef struct s_sphere_attrs
{
	double	radius;
}	t_sphere_attrs;

typedef struct s_figure t_figure;

t_figure	*new_sphere(char **parts);

#endif
