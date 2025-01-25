/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:35 by cfidalgo         ###   ########.fr       */
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
# include "exporter/exporter.h"
# include "window/loader/loader.h"
# include "jobs/jobs.h"
# include "textures/textures.h"
# include "cursor/window_cursor.h"
# include "composer/composer.h"
# include "controls/window_controls.h"

typedef struct s_resize
{
	t_size	size;
	int		to_resize;
}	t_resize;

typedef struct s_window
{
	char			*filename;
	t_size			size;
	mlx_texture_t	*icon;
	mlx_t			*mlx;
	t_render		render;
	t_render		*renders;
	t_resize		resize;
	double			last_scroll;
	t_exporter		exporter;
	t_loader		loader;
	t_jobs			jobs;
	t_textures		textures;
	double			last_update;
	t_cursor		cursor;
	t_composer		composer;
	t_controls		controls;
}	t_window;

void	init_window(t_window *window);

void	close_window(t_window *window);

#endif
