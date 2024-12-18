/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_composer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:31:35 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/18 15:33:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "utils/utils_bonus.h"
#include "libft.h"

char	*compose_cone(t_figure *figure)
{
	char	*str;

	str = NULL;
	join_format_str(&str, NULL, coordtoa(&figure->co_attrs->orientation), SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->co_attrs->radius * 2, 3), SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->co_attrs->height, 3), SEP);
	return (str);
}
