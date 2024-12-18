/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_composer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:54:25 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/18 15:34:33 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "utils/utils_bonus.h"
#include "libft.h"

char	*compose_sphere(t_figure *figure)
{
	char	*str;

	str = NULL;
	join_format_str(&str, NULL, ft_dtoa(figure->sp_attrs->radius * 2, 3), SEP);
	return (str);
}
