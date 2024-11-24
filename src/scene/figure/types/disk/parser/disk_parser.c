/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:49:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/24 16:50:36 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "scene/figure/figure.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "parser/helpers/parser_helper.h"

void	check_disk_parsing(t_parser_ctx *ctx, t_figure *disk)
{
	check_ori_vector_parsing(ctx, &disk->di_attrs->orientation);
	if (disk->di_attrs->radius <= 0)
		throw_parse_err(ctx, "Disk diameter must be a positive value");
}
