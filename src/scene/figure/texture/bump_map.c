/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:35:41 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 19:32:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bump_map.h"
#include "utils/utils_bonus.h"
#include "window/textures/textures.h"
#include <string.h>
#include <errno.h>

void	print_texture(t_bump_map *texture)
{
	char	*format_str;

	if (texture->format == OPENGL)
		format_str = "OpenGL";
	else
		format_str = "DirectX";
	ft_printf("TEXTURE (%s): %p\n", format_str, texture->texture);
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

void	parse_texture(t_parser_ctx *ctx, t_bump_map *bump_map, char **params)
{
	check_file(ctx, params[0]);
	bump_map->texture = get_texture(ctx->textures, params[0]);
	bump_map->format = OPENGL;
	if (params[1] && ft_strcmp(params[1], "directx") == EQUAL_STRINGS)
		bump_map->format = DIRECTX;
}
