/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:07:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/03 14:20:57 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/color/color.h"

void	sum_colors(t_color *first_color, t_color second_color, t_color *res);

void	mix_colors(t_color *first_color, t_color *second_color, t_color *res);

void	multiply_color_scalar(t_color *color, float scalar, t_color *res);
