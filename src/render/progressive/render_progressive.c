/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_progressive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:40:45 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/14 21:42:29 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils_bonus.h"
#include "libft.h"
#include "render_progressive.h"

void	init_progressive(t_progressive *prog, t_size size)
{
	unsigned int	i;

	prog->size.width = size.width;
	prog->size.height = size.height;
	prog->i = 0;
	if (prog->colors)
		free_colors(prog->colors);
	prog->colors = ft_calloc(prog->size.width + 1, sizeof(t_color *));
	if (!prog->colors)
		throw_sys_error("Allocating progressive buffer rows");
	i = 0;
	while (i < prog->size.width)
	{
		prog->colors[i] = ft_calloc(prog->size.height, sizeof(t_color));
		if (!prog->colors)
			throw_sys_error("Allocating progressive buffer col");
		i++;
	}
}

void	free_colors(t_color **colors)
{
	unsigned int	i;

	i = 0;
	while (colors[i])
		free(colors[i++]);
	free(colors);
}
