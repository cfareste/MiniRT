/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:16:26 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/17 18:11:00 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_round(double n)
{
	double	decimal_part;

	decimal_part = n - (int) n;
	if (decimal_part >= 0.5)
		n += 1.0 - decimal_part;
	else
		n -= decimal_part;
	return (n);
}

static double	get_decimal_value(double n, int precision)
{
	int		i;
	double	decimal_value;

	if (n < 0.0)
		n *= -1;
	i = 0;
	n = n - (unsigned long long) n;
	if (n >= 0.99999)
		n -= 0.001;
	while (i++ < precision)
		n *= 10;
	decimal_value = ft_round(n);
	return (decimal_value);
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

static char	*get_decimal_part(double decimal_value, int precision)
{
	int					i;
	char				*aux;
	char				*zeros_aux;
	char				*decimal_part;
	unsigned long long	parsed_decimal;

	parsed_decimal = decimal_value;
	i = 0;
	while (parsed_decimal > 0)
	{
		parsed_decimal /= 10;
		i++;	
	}
	zeros_aux = ft_calloc((precision - i) + 1, sizeof(char));
	if (!zeros_aux)
		return (NULL);
	precision -= i;
	i = 0;
	while (i < precision)
		zeros_aux[i++] = '0';
	aux = ft_ultoa((unsigned long long) decimal_value);
	if (!aux)
		return (free(zeros_aux), NULL);
	decimal_part = ft_strjoin(zeros_aux, aux);
	return (free(zeros_aux), free(aux), decimal_part);
}

char	*ft_dtoa(double n, int precision)
{
	double	decimal_value;
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
	decimal_part = get_decimal_part(decimal_value, precision);
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
