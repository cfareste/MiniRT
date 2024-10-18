/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:58:57 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/18 11:40:02 by arcanava         ###   ########.fr       */
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

double	ft_atod(char *str, void (*crash)(char *), char *param)
{
	char		**parts;
	double		num;
	long long	mod;
	int			i;
	int			neg;

	parts = ft_split(str, '.');
	if (!parts)
		return (crash(param), 0);
	i = -1;
	neg = is_negative(parts[0]);
	num = (double) ft_atoll(parts[0]);
	if (parts[1] && *parts[1])
	{
		i = -1;
		mod = 1;
		while (parts[1][++i])
			mod *= 10;
		if (neg)
			num -= (double) ft_atoll(parts[1]) / mod;
		else
			num += (double) ft_atoll(parts[1]) / mod;
	}
	free_matrix(parts);
	return (num);
}
