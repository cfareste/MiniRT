/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closest_multiple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:48:44 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/24 18:50:58 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_closest_multiple(long n, long x)
{
	return (n - (n % x));
}
