/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:21:20 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1422
# endif
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 800
# endif
# define ICON_PATH "assets/images/icon.png"
# define KEY_REPEAT_RATE 0.04

# include "render/render.h"
# include "utils/size/size.h"

typedef struct s_window
{
	char			*filename;
	t_size			size;
	mlx_texture_t	*icon;
	mlx_t			*mlx;
	t_render		render;
}	t_window;

void	init_window(t_window *window);

void	close_window(t_window *window);

#endif
