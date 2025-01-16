/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:01:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/16 18:10:45 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser.h"
#include "utils/utils_bonus.h"
#include "render/render_bonus.h"
#include "scene/figure/material/material.h"
#include "render/utils/random/random.h"
#include "scene/figure/material/helpers/material_helpers.h"
#include <math.h>

static int	is_metallic_scatter(float specular_index, float cos, uint64_t *seed)
{
	float	diffuse_scatter_probability;
	float	fresnel_effect_probability;

	diffuse_scatter_probability = get_random_float(seed);
	fresnel_effect_probability = get_random_float(seed);
	if (specular_index > diffuse_scatter_probability
		|| (specular_index && pow(1 - cos, 5) > fresnel_effect_probability))
		return (1);
	return (0);
}

static int	scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint64_t *seed)
{
	t_metallic_attrs	attrs;
	t_vector			reversed_ray_dir;
	float				cos;
	float				specular_index;

	multiply_vector_scalar(&params->ray->direction, -1, &reversed_ray_dir);
	cos = dot(&reversed_ray_dir, &params->hit_record.normal);
	specular_index = params->hit_record.figure
		->material.plastic_attrs->specular_index;
	attrs.roughness = params->hit_record.figure
		->material.plastic_attrs->roughness;
	params->attrs = &attrs;
	if (is_metallic_scatter(specular_index, cos, seed))
		return (metallic_scatter(render, params, direct_light, seed));
	else
		diffuse_scatter(render, params, direct_light, seed);
	return (1);
}

static char	*compose_plastic(t_material *material)
{
	char	*str;

	str = NULL;
	join_format_str(&str, "plastic:",
		ft_dtoa(material->plastic_attrs->specular_index, 3), ':');
	join_format_str(&str, NULL, ft_dtoa(material->plastic_attrs->roughness, 3),
		':');
	return (str);
}

t_material	new_plastic_mat(t_plastic_attrs *attrs)
{
	t_material	plastic_mat;

	plastic_mat.type = PLASTIC;
	plastic_mat.scatter = scatter;
	plastic_mat.compose = compose_plastic;
	plastic_mat.plastic_attrs = ft_calloc(1, sizeof(t_plastic_attrs));
	if (!plastic_mat.plastic_attrs)
		throw_sys_error("trying to allocate plastic attributes");
	plastic_mat.plastic_attrs->roughness = attrs->roughness;
	plastic_mat.plastic_attrs->specular_index = attrs->specular_index;
	return (plastic_mat);
}
