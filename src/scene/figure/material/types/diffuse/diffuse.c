/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:35:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 12:47:09 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/material/material.h"

static void	scatter(t_ray *ray, t_hit_record *hit_record, uint32_t *seed)
{
	(void) ray;
	(void) hit_record;
	(void) seed;
}

void	parse_diffuse(t_material *material)
{
	material->type = DIFFUSE;
	material->material_attrs = NULL;
	material->scatter = scatter;
}
