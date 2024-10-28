/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:50 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 19:48:51 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strncmp.h"

void	ft_jump_spaces(char **str)
{
	while (str && *str && **str && ft_stroccurrences(SPACES_CHARS, **str))
		(*str)++;
}
