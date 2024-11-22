/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:55:12 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/24 18:51:08 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_clamp(int value, int min, int max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	return (value);
}

double	ft_clampd(double value, double min, double max)
{
	if (value < min)
		value = max;
	else if (value > max)
		value = max;
	return (value);
}

float	ft_fclamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	return (value);
}

double	ft_overflowd(double value, double min, double max)
{
	if (value < min)
		value = max;
	else if (value > max)
		value = min;
	return (value);
}