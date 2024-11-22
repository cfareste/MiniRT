/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:01:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/22 20:09:18 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser.h"
#include "utils/utils_bonus.h"
#include "render/render_bonus.h"
#include "scene/figure/material/material.h"
#include "parser/helpers/parser_helper.h"
#include "render/utils/random/random.h"
#include "scene/figure/material/helpers/material_helpers.h"
#include <math.h>

static int	is_metallic_scatter(float specular_index, float cos, uint32_t *seed)
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
	t_color *direct_light, uint32_t *seed)
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

static void	check_parsing(t_parser_ctx *ctx, t_material *material)
{
	if (material->plastic_attrs->specular_index < 0
		|| material->plastic_attrs->specular_index > 1)
		throw_parse_err(ctx, "Specular index must be in range [0,1]");
	if (material->plastic_attrs->roughness < 0
		|| material->plastic_attrs->roughness > 1)
		throw_parse_err(ctx, "Plastic roughness must be in range [0,1]");
}

void	parse_plastic(t_parser_ctx *ctx, char **attrs_str, t_material *material)
{
	if (ft_matrix_len(attrs_str) < 2)
		throw_parse_err(ctx, "Missing some plastic attributes");
	material->type = PLASTIC;
	material->plastic_attrs = ft_calloc(1, sizeof(t_plastic_attrs));
	if (!material->plastic_attrs)
		throw_sys_error("trying to allocate plastic attributes");
	material->plastic_attrs->specular_index = parse_double(ctx, attrs_str[0]);
	material->plastic_attrs->roughness = parse_double(ctx, attrs_str[1]);
	material->scatter = scatter;
	check_parsing(ctx, material);
}
