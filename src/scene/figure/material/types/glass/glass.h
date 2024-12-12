/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:39:30 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:01:00 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define GLASS_ID "glass"

typedef struct s_glass_attrs
{
	float	refractive_index;
	float	transparency;
}	t_glass_attrs;

typedef struct s_material	t_material;

t_material	new_glass_mat(t_glass_attrs *attrs);
