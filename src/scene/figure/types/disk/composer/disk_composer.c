/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_composer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:43:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:33 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "utils/utils.h"
#include "libft.h"

char	*compose_disk(t_figure *figure)
{
	char	*str;

	str = NULL;
	join_format_str(&str, NULL, coordtoa(&figure->di_attrs->orientation, 3),
		SEP);
	join_format_str(&str, NULL, ft_dtoa(figure->di_attrs->radius * 2, 3), SEP);
	return (str);
}
