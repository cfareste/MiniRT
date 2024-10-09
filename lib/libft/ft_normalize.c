/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:55:12 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/24 18:51:08 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_normalize(int value, int min, int max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	return (value);
}
