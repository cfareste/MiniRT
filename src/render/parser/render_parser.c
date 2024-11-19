/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:18:46 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 22:14:18 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render_parser.h"
#include "utils/utils_bonus.h"
#include "parser/helpers/parser_helper.h"

static void	try_parse_err(t_parser_ctx *ctx, char *arg,
				t_render *render)
{
	char	**args;

	args = safe_ft_split(arg, ':',
				throw_sys_error, "trying to split render elem params");
	ft_printf("args: %s\n", args[0]);
	// TODO: parse render opts
}

int	try_parse_render_elems(t_parser_ctx *ctx, char **args,
				t_render *render)
{
	int	i;

	(void) ctx;
	(void) args;
	(void) render;
	if (ft_strncmp(RENDER_PARSE_ID, args[0],
			ft_strlen(RENDER_PARSE_ID)) != EQUAL_STRINGS)
		return (0);
	i = 1;
	while (args[i])
	{
		if (!try_parse_render_elem(ctx, args[i], render))
			throw_parse_err(ctx, ft_strjoin("Unknown render option: ",
				args[i]));
		i++;
	}
	return (0);
}
