/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_cylinder.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 20:15:10 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

void	get_cylinder_bump_normal(t_figure *figure, t_point *point, int is_base,
			t_vector *res);
