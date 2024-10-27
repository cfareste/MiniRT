/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:41 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:56:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "size.h"

t_size	new_size(int height, int width)
{
	t_size	size;

	size.height = height;
	size.width = width;
	return (size);
}
