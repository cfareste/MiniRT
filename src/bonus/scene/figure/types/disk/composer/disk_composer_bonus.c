/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_composer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:43:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"
#include "utils/utils_bonus.h"
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
