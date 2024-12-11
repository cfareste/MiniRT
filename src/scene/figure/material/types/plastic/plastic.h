/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:41:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 11:42:08 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PLASTIC_ID "plastic"

#include "parser/parser.h"

typedef struct s_plastic_attrs
{
	float	specular_index;
	float	roughness;
}	t_plastic_attrs;

typedef struct s_material	t_material;

t_material	new_plastic_mat(t_plastic_attrs *attrs);
