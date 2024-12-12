/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:28:11 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/12 16:04:16 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composition.h"

#include "libft.h"

void	*composition_routine(t_composition *composition)
{
	int	i;
	int	j;

	if (!composer_is_alive(composition->composer))
		return (free(composition), NULL);
	i = 0;
	while (composer_is_alive(composition->composer) && i < 20000000)
	{
		printf("Composing...\n");
		j = 0;
		while (composer_is_alive(composition->composer) && j < 1000)
			j++;
		i++;
	}
	return (free(composition), NULL);
}
