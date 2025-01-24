/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:58 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 10:28:40 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "utils/size/size.h"
#include "window/window.h"
#include <pthread.h>

t_window	*get_window(t_window *window)
{
	static t_window	*ctx = NULL;

	if (window)
		ctx = window;
	return (ctx);
}
