/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:49:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 20:09:51 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/vector/parser/vector_parser.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/figure_parser.h"
#include "libft.h"

static void	check_disk_parsing(t_parser_ctx *ctx, t_figure *disk)
{
	check_ori_vector_parsing(ctx, &disk->di_attrs->orientation);
	if (disk->di_attrs->radius <= 0)
		throw_parse_err(ctx, "Disk diameter must be a positive value");
}

t_figure	*parse_disk(t_parser_ctx *ctx, char **parts)
{
	t_figure		*disk;
	t_point			position;
	t_color			color;
	t_disk_attrs	disk_attrs;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 2)
		throw_parse_err(ctx, "Missing some disk parameter");
	parse_coordinates(ctx, parts[FIG_LAST_ATT], &position);
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1], &disk_attrs.orientation);
	disk_attrs.radius = parse_double(ctx, parts[FIG_LAST_ATT + 2]) / 2.0;
	parse_color(ctx, parts[FIG_LAST_ATT + 3], &color);
	disk = new_disk(&position, &color, &disk_attrs);
	set_figure_optionals(ctx, disk, &parts[FIG_LAST_ATT + 4]);
	check_disk_parsing(ctx, disk);
	return (disk);
}
