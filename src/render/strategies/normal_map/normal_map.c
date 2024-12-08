/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:30:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/08 17:18:40 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "render/strategies/shared/strategies_shared.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "libft.h"

void	compute_normal_map(t_scene *scene, t_ray *ray, t_color *sample_color)
{
	t_hit_record	hit_record;

	ft_bzero(&hit_record, sizeof(t_hit_record));
	check_collisions(scene, ray, &hit_record);
	get_normal_color(sample_color, &hit_record.normal);
	if (scene->selection && scene->selection == hit_record.figure)
		sum_color_scalar(sample_color, 0.3, sample_color);
}
