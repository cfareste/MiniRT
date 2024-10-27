/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:55:59 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
}	t_coordinates;

void	set_coordinates(char *str, t_coordinates *coordinates);
