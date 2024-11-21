/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:29:40 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/21 19:52:26 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "textures.h"
#include "window/loader/multi_loader_bonus.h"

t_texture	*push_texture(t_textures *textures, char *filename)
{
	t_texture	*texture;

	texture = ft_calloc(1, sizeof(t_texture));
	if (!texture)
		throw_sys_error("allocating texture");
	texture->path = ft_strdup(filename);
	texture->next = textures->texture;
	textures->texture = texture;
	textures->amount += 1;
	return (texture);
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

t_texture	*get_texture(t_textures *textures, char *path)
{
	t_texture	*texture;

	texture = textures->texture;
	while (texture && ft_strcmp(texture->path, path) != EQUAL_STRINGS)
		texture = texture->next;
	if (!texture)
		texture = push_texture(textures, path);
	return (texture);
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

void	load_textures(t_multi_loader *loader, t_textures *textures,
				t_jobs *jobs)
{
	t_texture	*texture;

	(void) loader;
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
