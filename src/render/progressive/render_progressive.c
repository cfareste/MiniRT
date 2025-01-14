/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_progressive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:40:45 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/14 17:43:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils_bonus.h"
#include "libft.h"
#include "render_progressive.h"
#include "../strategies/strategies.h"

void	init_progressive(t_rend_prog *prog, t_size *size)
{
	prog->colors = ft_calloc(size->width * size->height + 1,
			sizeof(t_color));
	if (!prog->colors)
		throw_sys_error("Allocating progressive buffer");
}
