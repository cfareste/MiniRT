/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:58:09 by arcanava          #+#    #+#             */
/*   Updated: 2024/07/16 12:12:05 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_sort(char **matrix)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[j])
		{
			if (ft_strcmp(matrix[i], matrix[j]) < 0)
			{
				aux = matrix[j];
				matrix[j] = matrix[i];
				matrix[i] = aux;
			}
			j++;
		}
		i++;
	}
}

void	ft_matrix_sort_lc(char **matrix)
{
	int		i;
	int		j;
	char	*aux;
	char	*compare[2];

	i = 0;
	while (matrix[i])
	{
		compare[0] = ft_strtolower(matrix[i]);
		j = 0;
		while (matrix[j])
		{
			compare[1] = ft_strtolower(matrix[j]);
			if (ft_strcmp(compare[0], compare[1]) < 0)
			{
				aux = matrix[j];
				matrix[j] = matrix[i];
				matrix[i] = aux;
			}
			free(compare[1]);
			j++;
		}
		free(compare[0]);
		i++;
	}
}
