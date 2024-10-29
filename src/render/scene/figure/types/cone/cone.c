/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:57:22 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/29 12:31:19 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "../../parser/figure_parser.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "render/scene/figure/figure.h"

static void	print_attrs(void *param)
{
	t_cone_attrs	*attrs;

	attrs = (t_cone_attrs *) param;
	printf("%f, %f, %f | %f | %f ",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->radius, attrs->height);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_coordinates	cone_to_ray;
	float			n_dot_pltoray;
	float			n_dot_rdir;
	float			root;

	n_dot_rdir = dot(&figure->co_attrs->orientation, &ray->direction);
	if (n_dot_rdir == 0.0)
		return (0);
	cone_to_ray.x = ray->origin.x - figure->position.x;
	cone_to_ray.y = ray->origin.y - figure->position.y;
	cone_to_ray.z = ray->origin.z - figure->position.z;
	n_dot_pltoray = -1 * dot(&figure->co_attrs->orientation, &cone_to_ray);
	root = n_dot_pltoray / n_dot_rdir;
	if (root <= ray->bounds.min || root >= ray->bounds.max)
		return (0);
	*distance = root;
	return (1);
}

static void	normal(t_figure *figure, t_coordinates *point, \
						t_coordinates *res)
{
	(void) point;
	res->x = figure->co_attrs->orientation.x;
	res->y = figure->co_attrs->orientation.y;
	res->z = figure->co_attrs->orientation.z;
}

static void	check_parsing(t_parser_ctx *ctx, t_figure *cone)
{
	check_ori_vector_parsing(ctx, &cone->co_attrs->orientation);
	if (cone->co_attrs->radius <= 0)
		throw_parse_err(ctx, "Cone diameter must be a positive value");
	else if (cone->co_attrs->height < 0)
		throw_parse_err(ctx, "Cone height must be a positive value");
}

t_figure	*parse_cone(t_parser_ctx *ctx, char **parts)
{
	t_figure	*cone;

	if (ft_matrix_len(parts) != FIG_ATT_LEN + 3)
		throw_error("Missing some cone parameter");
	cone = parse_figure(ctx, parts, FIG_LAST_ATT + 4);
	cone->co_attrs = ft_calloc(1, sizeof(t_cone_attrs));
	if (!cone->co_attrs)
		throw_sys_error("trying to allocate cone attributes");
	cone->print_attrs = print_attrs;
	cone->hit = hit;
	cone->normal = normal;
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1],
		&cone->co_attrs->orientation);
	cone->co_attrs->radius = parse_double(ctx, parts[FIG_LAST_ATT + 2]) / 2.0;
	cone->co_attrs->height = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	normalize(&cone->co_attrs->orientation);
	check_parsing(ctx, cone);
	return (cone);
}
