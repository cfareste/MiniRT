/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:40:40 by arcanava          #+#    #+#             */
/*   Updated: 2024/07/09 14:55:41 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	is_inside_limits(char *str, long long max, long long min)
{
	char	*s_max;
	char	*s_min;
	int		result;

	s_max = safe_ft_ltoa(max);
	s_min = safe_ft_ltoa(min);
	result = (*str != '-' && ft_strcmp(str, s_max) <= EQUAL_STRINGS)
		|| (*str == '-' && ft_strcmp(str, s_min) <= EQUAL_STRINGS);
	free(s_max);
	free(s_min);
	return (result);
}

int	ft_isnum_lim(char *str, long long max, long long min)
{
	int				is_num;
	int				symbols;
	unsigned int	digits_amount;
	unsigned int	max_digits;

	if (!str || !*str)
		return (0);
	is_num = is_inside_limits(str, max, min);
	max_digits = count_ull_digits(max);
	symbols = 0;
	while (is_num && *str && (*str == '+' || *str == '-') && symbols++ == 0)
		str++;
	while (is_num && *str && *(str + 1) && *str == '0')
		str++;
	digits_amount = 0;
	is_num = is_num && ft_isdigit(*str);
	while (is_num && *str && symbols <= 1)
	{
		is_num = ft_isdigit(*str) && digits_amount < max_digits;
		digits_amount++;
		str++;
	}
	return (is_num);
}

int	ft_isnum(char *str)
{
	int				is_num;
	int				symbols;

	if (!str || !*str)
		return (0);
	symbols = 0;
	while (*str && (*str == '+' || *str == '-') && symbols++ == 0)
		str++;
	while (*str && *(str + 1) && *str == '0')
		str++;
	is_num = ft_isdigit(*str);
	while (is_num && *str && symbols <= 1)
	{
		is_num = ft_isdigit(*str);
		str++;
	}
	return (is_num);
}
