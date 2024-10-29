/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:16 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/29 12:13:13 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_matrix(char **space)
{
	int	i;

	if (!space)
		return ;
	i = 0;
	while (*(space + i) != NULL)
	{
		free(*(space + i));
		i++;
	}
	free(space);
}

int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}