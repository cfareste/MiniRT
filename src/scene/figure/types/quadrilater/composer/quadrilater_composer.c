/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_composer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:50:14 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/20 13:52:38 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "utils/utils_bonus.h"
#include "libft.h"

char	*compose_quadrilater(t_figure *figure)
{
	char	*str;

	str = NULL;
	join_format_str(&str, NULL, coordtoa(&figure->qu_attrs->right), SEP);
	join_format_str(&str, NULL, coordtoa(&figure->qu_attrs->up), SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->qu_attrs->width, 3), SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->qu_attrs->height, 3), SEP);
	return (str);
}
