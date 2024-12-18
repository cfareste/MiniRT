/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:16:26 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 01:25:33 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_decimal_value(double n, int precision)
{
	int	i;
	int	exponent;

	if (n < 0.0)
		n *= -1;
	i = 0;
	exponent = 1;
	while (i < precision)
	{
		exponent *= 10;
		i++;
	}
	return ((n - (int) n) * exponent);
}

static char	*get_integer_part(double n)
{
	char	*aux;
	char	*integer_part;

	aux = ft_itoa(n);
	if (!aux)
		return (NULL);
	if (n >= 0.0)
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
	decimal_part = ft_itoa(decimal_value);
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
