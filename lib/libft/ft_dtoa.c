/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:16:26 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/20 16:50:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double ft_round(double n)
{
	double	decimal_part;

	decimal_part = n - (int) n;
	if (decimal_part >= 0.5)
		n += 1.0 - decimal_part;
	else
		n -= decimal_part;
	return (n);
}

static int	get_decimal_value(double n, int precision)
{
	int	i;
	int	decimal_part;

	if (n < 0.0)
		n *= -1;
	i = 0;
	n = n - (int) n;
	while (i++ < precision)
		n *= 10;
	decimal_part = ft_round(n);
	if (!decimal_part)
		return (decimal_part);
	while (decimal_part % 10 == 0)
		decimal_part /= 10;
	return (decimal_part);
}

static char	*get_integer_part(double n)
{
	char	*aux;
	char	*integer_part;

	aux = ft_ltoa(n);
	if (!aux)
		return (NULL);
	if (n <= -1.0 || n >= 0.0)
		return (aux);
	integer_part = ft_strjoin("-", aux);
	free(aux);
	return (integer_part);
}

char	*ft_dtoa(double n, int precision)
{
	int		decimal_value;
	char	*integer_part;
	char	*decimal_part;
	char	*aux;
	char	*num;

	integer_part = get_integer_part(n);
	if (!integer_part)
		return (NULL);
	decimal_value = get_decimal_value(n, precision);
	if (!decimal_value)
		return (integer_part);
	decimal_part = ft_ultoa(decimal_value);
	if (!decimal_part)
		return (free(integer_part), NULL);
	aux = ft_strjoin(integer_part, ".");
	free(integer_part);
	if (!aux)
		return (free(decimal_part), NULL);
	num = ft_strjoin(aux, decimal_part);
	free(aux);
	free(decimal_part);
	return (num);
}
