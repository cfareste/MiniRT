/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_args.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:48:19 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/22 13:48:40 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../strategies/strategy.h"

typedef struct s_render_args
{
	int			persist;
	int			resize;
	int			prog_enabled;
	t_strategy	strategy;
	t_strategy	cheap_strategy;
	int			cheap_enabled;
	int			dis_cheap_once;
}	t_render_args;