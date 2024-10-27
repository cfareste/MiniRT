/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:43 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:56:44 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_window_size
{
	unsigned int	width;
	unsigned int	height;
}	t_size;

t_size	new_size(int height, int width);
