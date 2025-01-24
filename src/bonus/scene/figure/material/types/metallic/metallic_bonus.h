/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:43:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 21:14:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define METALLIC_ID "metallic"

typedef struct s_metallic_attrs
{
	float	roughness;
}	t_metallic_attrs;

typedef struct s_material	t_material;

t_material	new_metallic_mat(t_metallic_attrs *attrs);
