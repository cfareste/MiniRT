/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroccurrences.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:32:35 by arcanava          #+#    #+#             */
/*   Updated: 2024/06/19 04:41:34 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_stroccurrences(char *str, char c)
{
	int	occurrences;

	occurrences = 0;
	while (str && *str)
	{
		if (*str == c)
			occurrences++;
		str++;
	}
	return (occurrences);
}

int	ft_stroccurrences_set(char *str, char *set)
{
	int	occurrences;

	occurrences = 0;
	while (str && *str)
	{
		if (ft_stroccurrences(set, *str))
			occurrences++;
		str++;
	}
	return (occurrences);
}
