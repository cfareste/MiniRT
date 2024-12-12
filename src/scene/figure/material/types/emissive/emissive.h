/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:34:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:11:02 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define EMISSIVE_ID "emissive"

#include "parser/parser.h"

typedef struct s_emissive_attrs
{
	float	intensity;
}	t_emissive_attrs;

typedef struct s_material	t_material;

t_material	new_emissive_mat(t_emissive_attrs *attrs);
