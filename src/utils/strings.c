/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:50 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:56:51 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strncmp.h"

void	jump_spaces(char **str)
{
	while (ft_strcmp(**str, ' ') == EQUAL_STRINGS)
		(*str)++;
}
