/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:42:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/26 14:43:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../camera.h"
#include "parser/parser.h"
#include "utils/utils_bonus.h"
#include "parser/helpers/parser_helper.h"
#include <math.h>

static void	check_parsing(t_parser_ctx *ctx, t_camera *camera)
{
	if (camera->front.x < -1.0 || camera->front.x > 1.0
		|| camera->front.y < -1.0 || camera->front.y > 1.0
		|| camera->front.z < -1.0 || camera->front.z > 1.0)
		throw_parse_err(ctx,
			"Camera orientation vector components must be in range [-1,1]");
	else if (camera->fov < 0 || camera->fov > 180)
		throw_parse_err(ctx,
			"Camera field of view (fov) must be in range [0,180]");
}

static void	calculate_defocus_components(t_camera *camera)
{
	float	defocus_radius;

	defocus_radius = tan(camera->defocus * 0.5 * M_PI / 180.0)
		* camera->focus_dist;
	multiply_vector_scalar(&camera->right, defocus_radius,
		&camera->defocus_right);
	multiply_vector_scalar(&camera->up, defocus_radius,
		&camera->defocus_up);
}

void	parse_camera(t_parser_ctx *ctx, char **parts, t_camera **camera)
{
	if (*camera)
		throw_parse_err(ctx, "Multiple cameras are not allowed");
	else if (!parts[1] || !parts[2] || !parts[3])
		throw_parse_err(ctx, "Missing camera params");
	*camera = ft_calloc(1, sizeof(t_camera));
	if (!*camera)
		throw_sys_error("trying to allocate t_camera");
	parse_coordinates(ctx, parts[1], &(*camera)->position);
	parse_coordinates(ctx, parts[2], &(*camera)->front);
	(*camera)->fov = parse_int(ctx, parts[3]);
	get_axes(&(*camera)->front, &(*camera)->right, &(*camera)->up);
	(*camera)->defocus = 0;
	(*camera)->focus_dist = 1;
	if (parts[4])
		(*camera)->defocus = parse_double(ctx, parts[4]);
	if (parts[4] && parts[5])
		(*camera)->focus_dist = parse_double(ctx, parts[5]);
	calculate_defocus_components(*camera);
	check_parsing(ctx, *camera);
}
