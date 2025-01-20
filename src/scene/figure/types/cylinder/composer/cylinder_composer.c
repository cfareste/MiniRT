/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_composer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/20 14:03:25 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "utils/utils_bonus.h"
#include "libft.h"

char	*compose_cylinder(t_figure *figure)
{
	char	*str;

	str = NULL;
	join_format_str(&str, NULL, coordtoa(&figure->cy_attrs->orientation, 3),
		SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->cy_attrs->radius * 2, 3), SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->cy_attrs->height, 3), SEP);
	return (str);
}
