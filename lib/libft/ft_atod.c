/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:58:57 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/20 17:00:13 by cfidalgo         ###   ########.fr       */
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

static void	sum_decimals(char *str, double *num, int is_negative)
{
	double	mod;
	int		i;

	i = 0;
	mod = 1;
	while (str[i++])
		mod *= 10;
	if (is_negative)
		*num -= (double) ft_atoll(str) / mod;
	else
		*num += (double) ft_atoll(str) / mod;
}

double	ft_atod(char *str)
{
	double	num;
	int		point_index;

	point_index = ft_index('.', str);
	if (point_index == -1)
		return ((double) ft_atoll(str));
	num = (double) ft_atoll(str);
	sum_decimals(str + point_index + 1, &num, is_negative(str));
	return (num);
}
