/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:50 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/07 09:55:16 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strncmp.h"

void	ft_jump_spaces(char **str)
{
	while (str && *str && **str && ft_stroccurrences(SPACES_CHARS, **str))
		(*str)++;
}

void	write_str(char *dst, char *src, int	*i)
{
	int	j;

	if (!dst || !src || !i)
		return ;
	j = 0;
	while (src[j])
		dst[(*i)++] = src[j++];
}
