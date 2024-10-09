/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:54:22 by arcanava          #+#    #+#             */
/*   Updated: 2024/07/03 17:52:01 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_ull_digits(unsigned long long nbr)
{
	int		i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	count_digits(long nbr)
{
	int		i;
	long	num;

	num = (long) nbr;
	if (nbr == 0)
		return (1);
	i = 0;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	count_hex_digits(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
		nbr /= 16 + (0 * i++);
	return (i);
}

long	get_positive_num(int n)
{
	long	nu;

	nu = n;
	if (nu < 0)
		nu *= -1;
	return (nu);
}
