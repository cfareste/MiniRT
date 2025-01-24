/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_composer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:07:54 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"
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
