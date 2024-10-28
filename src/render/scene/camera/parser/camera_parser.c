/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:42:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/28 20:42:23 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../camera.h"
#include "parser/parser.h"
#include "utils/utils.h"

void	parse_camera(t_parser_ctx *ctx, char **parts, t_camera **camera)
{
	t_vector	world_axis;

	(void) ctx;
	if (*camera)
		throw_error("Multiple cameras are not allowed");
	else if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing camera params");
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
}
