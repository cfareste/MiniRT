/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:39:30 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/17 21:03:52 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define GLASS_ID "glass"

typedef struct s_glass_attrs
{
	float	refractive_index;
	float	roughness;
}	t_glass_attrs;
