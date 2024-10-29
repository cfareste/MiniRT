/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:42:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/29 16:04:05 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../camera.h"
#include "parser/parser.h"
#include "utils/utils.h"

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

void	parse_camera(t_parser_ctx *ctx, char **parts, t_camera **camera)
{
	t_vector	world_axis;

	if (*camera)
		throw_parse_err(ctx, "Multiple cameras are not allowed");
	else if (!parts[1] || !parts[2] || !parts[3])
		throw_parse_err(ctx, "Missing camera params");
	*camera = ft_calloc(1, sizeof(t_camera));
	if (!*camera)
		throw_sys_error("trying to allocate t_camera");
	parse_coordinates(ctx, parts[1], &(*camera)->position);
	parse_coordinates(ctx, parts[2], &(*camera)->front);
	normalize(&(*camera)->front);
	(*camera)->fov = parse_int(ctx, parts[3]);
	get_axis(&world_axis, UP);
	if (dot(&(*camera)->front, &world_axis) == 1.0)
		get_axis(&world_axis, BACK);
	else if (dot(&(*camera)->front, &world_axis) == -1.0)
		get_axis(&world_axis, FRONT);
	cross(&(*camera)->front, &world_axis, &(*camera)->right);
	normalize(&(*camera)->right);
	cross(&(*camera)->right, &(*camera)->front, &(*camera)->up);
	normalize(&(*camera)->up);
	check_parsing(ctx, *camera);
}
