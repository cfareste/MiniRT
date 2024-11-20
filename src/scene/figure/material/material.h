/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:46:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 12:22:58 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/ray/ray.h"
#include "render/utils/hit_record/hit_record.h"
#include "scene/figure/material/types/glass/glass.h"
#include "scene/figure/material/types/diffuse/diffuse.h"
#include "scene/figure/material/types/plastic/plastic.h"
#include "scene/figure/material/types/metallic/metallic.h"
#include "scene/figure/material/types/emissive/emissive.h"

typedef enum e_material_type
{
	DIFFUSE,
	METALLIC,
	PLASTIC,
	GLASS,
	EMISSIVE
}	t_material_type;

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
	void			(*scatter)(t_ray *ray, t_hit_record *hit_record,
			uint32_t *seed);
}	t_material;