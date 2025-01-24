/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_composer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:47:09 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"
#include "utils/utils_bonus_bonus.h"

char	*compose_plane(t_figure *figure)
{
	char	*str;

	str = NULL;
	join_format_str(&str, NULL, coordtoa(&figure->pl_attrs->orientation, 3),
		SEP);
	return (str);
}
