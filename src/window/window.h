/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 20:53:20 by arcanava         ###   ########.fr       */
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

# include "MLX42.h"
# include "render/render_bonus.h"
# include "utils/size/size.h"
# include "exporter/exporter_bonus.h"
# include "loader/multi_loader_bonus.h"
# include "jobs/jobs.h"
# include "textures/textures.h"

typedef struct s_resize
{
	t_size	size;
	double	last_resize;
}	t_resize;

typedef struct s_window
{
	t_size			size;
	mlx_texture_t	*icon;
	mlx_t			*mlx;
	t_render		render;
	t_resize		resize;
	double			last_scroll;
	t_exporter		exporter;
	pthread_mutex_t	ready;
	t_multi_loader	loader;
	t_jobs			jobs;
	t_textures		textures;
}	t_window;

void	init_window(t_window *window);

#endif
