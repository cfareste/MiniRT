/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 18:20:16 by arcanava         ###   ########.fr       */
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

t_figure	*parse_sphere(t_parser_ctx *ctx, char **parts);

#endif
