/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:06:55 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/05 15:53:47 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_parser.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include "parser/helpers/parser_helper.h"

void	set_window_defaults(t_window *window)
{
	window->size.width = WINDOW_WIDTH;
	window->size.height = WINDOW_HEIGHT;
}

static int	try_parse_window_elem(t_parser_ctx *ctx, char *arg,
				t_window *window)
{
	char	**args;

	args = safe_ft_split(arg, ':',
			throw_sys_error, "trying to split window elem params");
	if (ft_strcmp(args[0], WINDOW_PARSE_WIDTH_ID) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		window->size.width = (unsigned int)
			ft_clamp(parse_int(ctx, args[1]), 1, WINDOW_WIDTH);
	else if (ft_strcmp(args[0], WINDOW_PARSE_HEIGHT_ID) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		window->size.height = (unsigned int)
			ft_clamp(parse_int(ctx, args[1]), 1, WINDOW_HEIGHT);
	else
	{
		free_matrix(args);
		return (0);
	}
	free_matrix(args);
	return (1);
}

int	try_parse_window_elems(t_parser_ctx *ctx, char **args, t_window *window)
{
	int	i;

	if (ft_strcmp(WINDOW_PARSE_ID, args[0]) != EQUAL_STRINGS)
		return (0);
	i = 1;
	while (args[i])
	{
		if (!try_parse_window_elem(ctx, args[i], window))
			throw_parse_err(ctx, ft_strjoin("Unknown window param: ",
					args[i]));
		i++;
	}
	return (1);
}
