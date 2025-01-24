/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:59:35 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1422
# endif
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 800
# endif
# define ICON_PATH "assets/images/icon.png"
# define KEY_REPEAT_RATE 0.04

# include "render/render_bonus_bonus.h"
# include "utils/size/size_bonus.h"
# include "exporter/exporter_bonus_bonus.h"
# include "window/loader/loader_bonus_bonus.h"
# include "jobs/jobs_bonus.h"
# include "textures/textures_bonus.h"
# include "cursor/window_cursor_bonus.h"
# include "composer/composer_bonus.h"
# include "controls/window_controls_bonus.h"

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
