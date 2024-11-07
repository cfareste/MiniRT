/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:35:41 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/07 17:51:31 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "texture.h"
#include "utils/utils_bonus.h"
#include <string.h>
#include <errno.h>

void	print_texture(t_bump_map *texture)
{
	char	*format_str;

	if (texture->format == OPENGL)
		format_str = "OpenGL";
	else
		format_str = "DirectX";
	printf("TEXTURE (%s): %p\n", format_str, texture->texture);
}

static void	check_file(t_parser_ctx *ctx, char *path)
{
	char	*err_pref;

	err_pref = ft_strjoin(path, ": ");
	if (!err_pref)
		throw_sys_error("Dynamic memory broken! texture.c:36");
	if (correct_file_extension(path, ".png")
		|| correct_file_extension(path, ".xpm42"))
	{
		if (access(path, F_OK | R_OK))
			throw_parse_err(ctx, safe_ft_strjoin(err_pref,
					strerror(errno), throw_sys_error,
					"Dynamic memory broken! texture.c:42"));
	}
	else
		throw_parse_err(ctx,
			"Only .png or .xpm42 are allowed for texture file!");
	free(err_pref);
}

// TODO: add path context!!
void	parse_texture(t_parser_ctx *ctx, t_bump_map *texture, char **params)
{
	if (!params[1])
		throw_parse_err(ctx, "Missing texture params");
	check_file(ctx, params[1]);
	if (correct_file_extension(params[1], ".png"))
	{
		texture->texture = mlx_load_png(params[1]);
		if (!texture->texture)
			throw_mlx_error(params[1], mlx_strerror(mlx_errno));
	}
	else if (correct_file_extension(params[1], ".xpm42"))
	{
		texture->xpm = mlx_load_xpm42(params[1]);
		if (!texture->xpm)
			throw_mlx_error(params[1], mlx_strerror(mlx_errno));
		texture->texture = &texture->xpm->texture;
	}
	texture->format = OPENGL;
	if (params[2] && ft_strcmp(params[2], "directx") == EQUAL_STRINGS)
		texture->format = DIRECTX;
}
