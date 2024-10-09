/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:49:14 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/30 12:43:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_putnbr(int fd, long n, int *count)
{
	unsigned long	nbr;
	char			res;

	if (n < 0)
	{
		ft_putstr(fd, "-", count);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr / 10 > 0 && *count > -1)
		ft_putnbr(fd, nbr / 10, count);
	res = nbr % 10 + '0';
	if (*count > -1)
		ft_putchar(fd, &res, count);
	return (*count);
}
