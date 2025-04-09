/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressive_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:59:36 by arcanava          #+#    #+#             */
/*   Updated: 2025/03/20 18:53:30 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "progressive_helper.h"
#include "libft.h"

void	reset_progress(t_rend_prog *progress, t_size *size,
			int parts_amount)
{
	int	i;
	int	j;

	i = 0;
	while (i < STRATEGIES_AMOUNT)
	{
		if (progress[i].colors)
			ft_bzero(progress[i].colors, size->width
				* size->height * sizeof(t_color));
		j = 0;
		while (j < parts_amount)
		{
			progress[i].iter[j].i = 0;
			progress[i].iter[j].j = 0;
			j++;
		}
		i++;
	}
}

void	restart_progress(t_rend_prog *progress,
			t_size *img_size)
{
	int	i;

	i = 0;
	while (i < STRATEGIES_AMOUNT)
	{
		if (progress[i].colors)
			free(progress[i].colors);
		ft_bzero(progress + i, sizeof(t_rend_prog));
		init_progressive(progress + i, img_size);
		i++;
	}
}

void	clean_progress(t_rend_prog *progress)
{
	int	i;

	i = 0;
	while (i < STRATEGIES_AMOUNT)
	{
		if (progress[i].colors)
		{
			free(progress[i].colors);
			ft_bzero(progress + i, sizeof(t_rend_prog));
		}
		i++;
	}
}
