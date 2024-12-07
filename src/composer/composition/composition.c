/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:28:11 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/07 16:06:08 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composition.h"
#include "window/loader/strategies/progress/helpers/loader_progress_helper.h"
#include "window/loader/helpers/loader_helper.h"

#include "libft.h"

void	*composition_routine(t_composition *composition)
{
	int	i;
	int	j;

	if (!composer_is_alive(composition->composer))
		return (free(composition), NULL);
	loader_show(composition->composer->loader, BAR, LOADER_SIZE_MINI);
	loader_set_total(composition->composer->loader, 20000000);
	i = 0;
	while (composer_is_alive(composition->composer) && i < 20000000)
	{
		printf("Composing...\n");
		loader_add_progress(composition->composer->loader);
		j = 0;
		while (composer_is_alive(composition->composer) && j < 1000)
			j++;
		i++;
	}
	loader_hide(composition->composer->loader);
	return (free(composition), NULL);
}
