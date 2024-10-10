/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:04:02 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/10 13:00:04 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_allowed_char(char c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' '
		|| c == '-'
		|| c == '+');
}

int	ft_atoi(const char *str)
{
	long	num;
	int		i;
	int		is_negative;
	int		symb_count;

	symb_count = 0;
	num = 0;
	i = 0;
	is_negative = 0;
	while (str && str[i] != '\0' && is_allowed_char(str[i]) && symb_count == 0)
	{
		if (str[i] == '-' || str[i] == '+')
			symb_count++;
		if (str[i] == '-')
			is_negative = 1;
		i++;
	}
	while (str && str[i] != '\0' && ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i++] - '0';
	}
	if (is_negative)
		num *= -1;
	return (num);
}

long	ft_atol(const char *str)
{
	long	num;
	int		i;
	int		is_negative;
	int		symbols_count;

	symbols_count = 0;
	num = 0;
	i = 0;
	is_negative = 0;
	while (str && str[i] && is_allowed_char(str[i]) && symbols_count == 0)
	{
		if (str[i] == '-' || str[i] == '+')
			symbols_count++;
		if (str[i] == '-')
			is_negative = 1;
		i++;
	}
	while (str && str[i] && ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i++] - '0';
	}
	if (is_negative)
		num *= -1;
	return (num);
}

long long	ft_atoll(const char *str)
{
	long long	num;
	int			i;
	int			is_negative;
	int			symbols_count;

	symbols_count = 0;
	num = 0;
	i = 0;
	is_negative = 0;
	while (str[i] != '\0' && is_allowed_char(str[i]) && symbols_count == 0)
	{
		if (str[i] == '-' || str[i] == '+')
			symbols_count++;
		if (str[i] == '-')
			is_negative = 1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i++] - '0';
	}
	if (is_negative)
		num *= -1;
	return (num);
}
