/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:29:40 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "textures_bonus.h"
#include "window/helpers/window_helper_bonus_bonus.h"
#include "utils/utils_bonus_bonus.h"
#include "window/jobs/job/types/destroy/destroy_job_bonus.h"
#include "window/jobs/job/helpers/job_helper_bonus.h"

static void	throw_mlx_error(const char *msg)
{
	t_window	*window;

	window = get_window(NULL);
	if (window->mlx)
		wait_job(push_job(&window->jobs, init_destroy_job(new_job())),
			NULL, NULL);
	ft_printff(STDERR_FILENO, "%s\n", msg);
	exit(EXIT_FAILURE);
}

void	print_textures(t_textures *textures)
{
	t_texture	*texture;

	texture = textures->texture;
	ft_printf("Textures: %d\n", textures->amount);
	while (texture)
	{
		ft_printf("%s: %p\n", texture->path, texture->mlx);
		texture = texture->next;
	}
}

void	free_textures(t_textures *textures)
{
	t_texture	*texture;
	t_texture	*aux;

	texture = textures->texture;
	while (texture)
	{
		if (texture->xpm)
			mlx_delete_xpm42(texture->xpm);
		else if (texture->mlx)
			mlx_delete_texture(texture->mlx);
		aux = texture;
		texture = texture->next;
		free(aux->path);
		free(aux);
	}
}

void	load_textures(t_textures *textures)
{
	t_texture	*texture;

	printf("Loading textures...\n");
	texture = textures->texture;
	while (texture)
	{
		if (correct_file_extension(texture->path, ".png"))
		{
			texture->mlx = mlx_load_png(texture->path);
			if (!texture->mlx)
				throw_mlx_error(mlx_strerror(MLX_INVPNG));
		}
		else if (correct_file_extension(texture->path, ".xpm42"))
		{
			texture->xpm = mlx_load_xpm42(texture->path);
			if (!texture->xpm)
				throw_mlx_error(mlx_strerror(MLX_INVXPM));
			texture->mlx = &texture->xpm->texture;
		}
		texture = texture->next;
	}
}
