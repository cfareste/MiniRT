/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:43:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 11:49:00 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define METALLIC_ID "metallic"

#include "parser/parser.h"

typedef struct s_metallic_attrs
{
	float	roughness;
}	t_metallic_attrs;

typedef struct s_material	t_material;

t_material	new_metallic_mat(t_metallic_attrs *attrs);
