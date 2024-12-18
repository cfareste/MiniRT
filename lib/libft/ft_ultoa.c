/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:16:26 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/17 19:24:03 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <limits.h>

static int	calculate_num_of_digits(unsigned long num)
{
	int	digits;

	digits = 0;
	while (num / 10 != 0)
	{
		digits++;
		num /= 10;
	}
	return (digits + 1);
}

static void	putnbr(char *num, unsigned long n, int index)
{
	if (n / 10 == 0)
		num[index] = n + '0';
	else
	{
		putnbr(num, n / 10, index - 1);
		num[index] = (n % 10) + '0';
	}
}

char	*ft_ultoa(unsigned long n)
{
	char	*num;
	int		num_of_digits;

	num_of_digits = calculate_num_of_digits(n);
	num = ft_calloc(num_of_digits + 1, sizeof(char));
	if (!num)
		return (NULL);
	putnbr(num, n, num_of_digits - 1);
	return (num);
}
