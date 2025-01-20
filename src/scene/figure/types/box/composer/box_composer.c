/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_composer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:07:54 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/20 14:02:59 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "utils/utils_bonus.h"
#include "libft.h"

char	*compose_box(t_figure *figure)
{
	char	*str;

	str = NULL;
	join_format_str(&str, NULL,
		coordtoa(&figure->bo_attrs->faces[0].attrs.right, 8), SEP);
	join_format_str(&str, NULL,
		coordtoa(&figure->bo_attrs->faces[0].attrs.up, 8), SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->bo_attrs->width, 3), SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->bo_attrs->height, 3), SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->bo_attrs->length, 3), SEP);
	return (str);
}
