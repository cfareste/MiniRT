/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:35:41 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bump_map_bonus.h"
#include "utils/utils_bonus_bonus.h"
#include "parser/helpers/parser_helper_bonus.h"
#include <string.h>
#include <errno.h>

void	print_texture(t_bump_map *texture)
{
	char	*format_str;

	if (texture->format == OPENGL)
		format_str = "OpenGL";
	else
		format_str = "DirectX";
	printf("TEXTURE (%s): %p | Dimension: %f\n",
		format_str, texture->texture, texture->width_dim);
}

void	check_file(t_parser_ctx *ctx, char *path)
{
	char	*err_pref;

	err_pref = ft_strjoin(path, ": ");
	if (!err_pref)
		throw_sys_error("Dynamic memory broken! texture.c:36");
	if (correct_file_extension(path, ".png")
		|| correct_file_extension(path, ".xpm42"))
	{
		if (access(path, F_OK))
			throw_parse_err(ctx, safe_ft_strjoin(err_pref,
					strerror(ENOENT), throw_sys_error,
					"Dynamic memory broken! texture.c:42"));
		if (access(path, R_OK))
			throw_parse_err(ctx, safe_ft_strjoin(err_pref,
					strerror(EACCES), throw_sys_error,
					"Dynamic memory broken! texture.c:42"));
	}
	else
		throw_parse_err(ctx,
			"Only .png or .xpm42 are allowed for texture file!");
	free(err_pref);
}

void	parse_texture(t_parser_ctx *ctx, t_bump_map *bump_map, char **params)
{
	if (!params[1] || !params[2])
		throw_parse_err(ctx, "Missing texture params");
	check_file(ctx, params[1]);
	bump_map->texture = get_texture(ctx->textures, params[1]);
	bump_map->width_dim = parse_double(ctx, params[2]);
	bump_map->format = OPENGL;
	if (params[3] && ft_strcmp(params[3], "directx") == EQUAL_STRINGS)
		bump_map->format = DIRECTX;
	if (bump_map->width_dim <= 0)
		throw_parse_err(ctx, "Texture width must be greater than 0");
}
