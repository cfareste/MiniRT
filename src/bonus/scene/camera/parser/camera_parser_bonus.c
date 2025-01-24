/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parser_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:42:03 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_parser_bonus.h"
#include "libft.h"
#include "utils/utils_bonus_bonus.h"
#include "parser/helpers/parser_helper_bonus.h"
#include "render/utils/vector/parser/vector_parser_bonus.h"

static void	check_parsing(t_parser_ctx *ctx, t_camera *camera)
{
	check_ori_vector_parsing(ctx, &camera->front);
	if (camera->fov < 0 || camera->fov > 180)
		throw_parse_err(ctx,
			"Camera field of view (fov) must be in range [0,180]");
	if (camera->defocus < 0)
		throw_parse_err(ctx, "Defocus radius must be a positive value");
	if (camera->focus_dist <= 0)
		throw_parse_err(ctx, "Focus distance must be a positive value");
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
