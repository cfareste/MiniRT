/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:58:57 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/10 17:38:54 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(char *str)
{
	int	neg;

	neg = 0;
	while (is_allowed_char(*str))
		if (*(str++) == '-')
			neg = !neg;
	return (neg);
}

double	ft_atod(char *str)
{
	char		**pieces;
	double		num;
	long long	mod;
	int			i;
	int			neg;

	pieces = ft_split(str, '.');
	i = -1;
	neg = is_negative(pieces[0]);
	num = (double) ft_atoll(pieces[0]);
	if (pieces[1] && *pieces[1])
	{
		i = -1;
		mod = 1;
		while (pieces[1][++i])
			mod *= 10;
		if (neg)
			num -= (double) ft_atoll(pieces[1]) / mod;
		else
			num += (double) ft_atoll(pieces[1]) / mod;
	}
	free_matrix(pieces);
	return (num);
}
