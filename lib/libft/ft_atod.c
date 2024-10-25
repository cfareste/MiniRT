/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:58:57 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/24 23:27:07 by arcanava         ###   ########.fr       */
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

static double	exec_ft_atod(char *str, void (*crash)(char *), char *param)
{
	char		**str_parts;
	double		num;
	long long	mod;
	int			i;
	int			neg;

	str_parts = ft_split(str, '.');
	if (!str_parts)
		return (crash(param), 0);
	i = -1;
	neg = is_negative(str_parts[0]);
	num = (double) ft_atoll(str_parts[0]);
	if (str_parts[1] && *str_parts[1])
	{
		i = -1;
		mod = 1;
		while (str_parts[1][++i])
			mod *= 10;
		if (neg)
			num -= (double) ft_atoll(str_parts[1]) / mod;
		else
			num += (double) ft_atoll(str_parts[1]) / mod;
	}
	free_matrix(str_parts);
	return (num);
}

double	ft_atod(char *str, void (*crash_fun)(char *), char *param)
{
	if (ft_stroccurrences(str, '.'))
		return (exec_ft_atod(str, crash_fun, param));
	else
		return ((double) ft_atol(str));
}
