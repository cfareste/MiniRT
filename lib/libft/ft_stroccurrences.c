/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroccurrences.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:32:35 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/28 19:26:26 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_index(char c, char *str)
{
	int	index;

	index = 0;
	while (str && str[index] && str[index] != c)
		index++;
	if (str[index] != c)
		return (-1);
	return (index);
}

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
