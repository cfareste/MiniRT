/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:41:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 21:10:12 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PLASTIC_ID "plastic"

typedef struct s_plastic_attrs
{
	float	specular_index;
	float	roughness;
}	t_plastic_attrs;

typedef struct s_material	t_material;

t_material	new_plastic_mat(t_plastic_attrs *attrs);
