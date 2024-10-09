/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:10:23 by arcanava          #+#    #+#             */
/*   Updated: 2024/07/15 23:07:58 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	result;

	result = c + 32;
	if (ft_isalpha(c) && ft_isalpha(result))
		return (result);
	else
		return (c);
}

char	*ft_strtolower(char *c)
{
	char	*new;
	int		i;

	new = safe_ft_strdup(c, exit);
	i = 0;
	while (new[i])
	{
		if (new[i] >= 'A' && new[i] <= 'Z')
			new[i] += 32;
		i++;
	}
	return (new);
}
