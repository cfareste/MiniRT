/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:46:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 21:09:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/color/color.h"
#include "render/utils/hit_record/hit_record.h"
#include "scene/figure/material/types/glass/glass.h"
#include "scene/figure/material/types/diffuse/diffuse.h"
#include "scene/figure/material/types/plastic/plastic.h"
#include "scene/figure/material/types/metallic/metallic.h"
#include "scene/figure/material/types/emissive/emissive.h"

#define AIR_REFRACTIVE_INDEX 1.0003
#define GLASS_REFRACTIVE_INDEX 1.52

typedef struct s_render	t_render;

typedef enum e_material_type
{
	DIFFUSE,
	METALLIC,
	PLASTIC,
	GLASS,
	EMISSIVE
}	t_material_type;

typedef struct s_scatter_params
{
	void				*attrs;
	t_ray				*ray;
	t_hit_record		hit_record;
	t_material_type		scatter_type;
}	t_scatter_params;

typedef struct s_material
{
	t_material_type	type;
	union
	{
		void				*material_attrs;
		t_metallic_attrs	*metallic_attrs;
		t_plastic_attrs		*plastic_attrs;
		t_glass_attrs		*glass_attrs;
		t_emissive_attrs	*emissive_attrs;
	};
	int				(*scatter)(t_render *render, t_scatter_params *params,
			t_color *direct_light, uint64_t *seed);
	char			*(*compose)(t_material *material);
}	t_material;
