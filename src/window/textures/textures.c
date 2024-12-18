/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:29:40 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 21:53:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include "textures.h"
#include "window/loader/loader_bonus.h"
#include "window/jobs/job/types/destroy/destroy_job.h"

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

void	throw_mlx_error(t_jobs *jobs, char *msg, const char *mlx_msg)
{
	ft_printff(STDERR_FILENO, "%s: %s: %s\n",
		PROGRAM_NAME, msg, mlx_msg);
	push_job(jobs, init_destroy_job(new_job()));
}

void	load_textures(t_textures *textures, t_jobs *jobs)
{
	t_texture	*texture;

	texture = textures->texture;
	while (texture)
	{
		if (correct_file_extension(texture->path, ".png"))
		{
			texture->mlx = mlx_load_png(texture->path);
			if (!texture->mlx)
				throw_mlx_error(jobs, texture->path, mlx_strerror(mlx_errno));
		}
		else if (correct_file_extension(texture->path, ".xpm42"))
		{
			texture->xpm = mlx_load_xpm42(texture->path);
			if (!texture->xpm)
				throw_mlx_error(jobs, texture->path, mlx_strerror(mlx_errno));
			texture->mlx = &texture->xpm->texture;
		}
		texture = texture->next;
	}
}
