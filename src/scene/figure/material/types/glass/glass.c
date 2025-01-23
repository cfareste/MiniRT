/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:50:15 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 21:23:27 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "render/strategies/shared/strategies_shared.h"
#include "scene/figure/material/helpers/material_helpers.h"
#include "render/utils/random/random.h"
#include <math.h>

static void	refractive_scatter(t_scatter_params *params, float cos,
	float index_ratio, uint64_t *seed)
{
	t_vector	perpendicular;
	t_vector	parallel;
	t_vector	new_ray_direction;
	float		parallel_scalar;
	float		perpendicular_length_squared;

	multiply_vector_scalar(&params->hit_record.normal, cos, &perpendicular);
	sum_vectors(&params->ray->direction, &perpendicular, &perpendicular);
	multiply_vector_scalar(&perpendicular, index_ratio, &perpendicular);
	perpendicular_length_squared = dot(&perpendicular, &perpendicular);
	parallel_scalar = sqrt(fabs(1.0 - perpendicular_length_squared)) * -1.0;
	multiply_vector_scalar(&params->hit_record.normal, parallel_scalar,
		&parallel);
	sum_vectors(&perpendicular, &parallel, &new_ray_direction);
	if (params->hit_record.figure->material.glass_attrs->transparency < 1)
		divert_ray_direction(&new_ray_direction,
			1 - params->hit_record.figure->material.glass_attrs->transparency,
			seed, &new_ray_direction);
	set_ray(params->ray, &params->hit_record.point, &new_ray_direction);
}

static int	is_metallic_scatter(float cos, float index, uint64_t *seed)
{
	float	sin;
	float	refractive_scatter_probability;

	sin = sqrt(1 - (cos * cos));
	refractive_scatter_probability = get_random_float(seed);
	if ((index * sin) > 1.0
		|| get_fresnel_effect(index, cos) > refractive_scatter_probability)
		return (1);
	return (0);
}

static int	scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint64_t *seed)
{
	int					is_front_face;
	float				cos;
	float				index_ratio;
	t_vector			reversed_ray_dir;
	t_metallic_attrs	attrs;

	attrs.roughness = 1 - params->hit_record.figure->material.glass_attrs
		->transparency;
	params->attrs = &attrs;
	index_ratio = params->hit_record.figure->material.glass_attrs
		->refractive_index;
	is_front_face
		= dot(&params->hit_record.normal, &params->ray->direction) <= 0.0;
	if (is_front_face)
		index_ratio = AIR_REFRACTIVE_INDEX / index_ratio;
	else
		multiply_vector_scalar(&params->hit_record.normal, -1,
			&params->hit_record.normal);
	multiply_vector_scalar(&params->ray->direction, -1, &reversed_ray_dir);
	cos = dot(&reversed_ray_dir, &params->hit_record.normal);
	if (is_metallic_scatter(cos, index_ratio, seed) && is_front_face)
		return (metallic_scatter(render, params, direct_light, seed));
	else
		refractive_scatter(params, cos, index_ratio, seed);
	return (1);
}

static char	*compose_glass(t_material *material)
{
	char	*str;

	str = NULL;
	join_format_str(&str, "glass:",
		ft_dtoa(material->glass_attrs->refractive_index, 3), ':');
	join_format_str(&str, NULL, ft_dtoa(material->glass_attrs->transparency, 3),
		SEP);
	return (str);
}

t_material	new_glass_mat(t_glass_attrs *attrs)
{
	t_material	glass_mat;

	glass_mat.type = GLASS;
	glass_mat.scatter = scatter;
	glass_mat.compose = compose_glass;
	glass_mat.glass_attrs = ft_calloc(1, sizeof(t_glass_attrs));
	if (!glass_mat.glass_attrs)
		throw_sys_error("trying to allocate glass attributes");
	glass_mat.glass_attrs->refractive_index = attrs->refractive_index;
	glass_mat.glass_attrs->transparency = attrs->transparency;
	return (glass_mat);
}
