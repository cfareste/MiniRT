/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:15:46 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 21:16:49 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../parser.h"

void	throw_parse_err(t_parser_ctx *ctx, char *error_msg)
{
	if (ctx->line)
		ft_printff(STDERR_FILENO, "Error\n%s:%d -> %s\n",
			ctx->filename, ctx->line, error_msg);
	else
		ft_printff(STDERR_FILENO, "Error\n%s -> %s\n",
			ctx->filename, error_msg);
	exit(EXIT_FAILURE);
}

double	parse_double(t_parser_ctx *ctx, char *str)
{
	char	*aux;
	int		symbols_count;
	int		points_count;
	int		nums_count;

	aux = str;
	symbols_count = 0;
	points_count = 0;
	nums_count = 0;
	ft_jump_spaces(&str);
	while (str && *str && symbols_count < 1
		&& !(ft_isdigit(*str) || *str == '.'))
		symbols_count += ft_stroccurrences("+-", *(str++));
	while (str && *str && symbols_count <= 1 && points_count <= 1
		&& (ft_isdigit(*str) || *str == '.'))
	{
		points_count += *str == '.';
		nums_count += ft_isdigit(*str);
		str++;
	}
	if (*str || symbols_count > 1 || points_count > 1 || nums_count < 1)
		throw_parse_err(ctx,
			ft_strjoin("Invalid floating point number: ", aux));
	return (ft_atod(aux));
}

int	parse_int(t_parser_ctx *ctx, char *str)
{
	if (!ft_isnum(str))
		throw_parse_err(ctx, ft_strjoin("Invalid integer number: ", str));
	return (ft_atoi(str));
}