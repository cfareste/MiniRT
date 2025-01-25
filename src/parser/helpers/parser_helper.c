/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:15:46 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:52:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_helper.h"
#include "libft.h"
#include "utils/utils.h"

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
		throw_parse_err(ctx, safe_ft_strjoin("Invalid floating point number: ",
				aux, throw_sys_error, "parsing"));
	return (ft_atod(aux));
}

int	parse_int(t_parser_ctx *ctx, char *str)
{
	if (!ft_isnum(str))
		throw_parse_err(ctx, safe_ft_strjoin("Invalid integer number: ", str,
				throw_sys_error, "parsing"));
	return (ft_atoi(str));
}

unsigned long	parse_ulong(t_parser_ctx *ctx, char *str)
{
	long long	num;

	num = ft_atoll(str);
	if (!ft_isnum(str) || num < 0)
		throw_parse_err(ctx, safe_ft_strjoin("Invalid unsigned long number: ",
				str, throw_sys_error, "parsing"));
	return ((unsigned long) num);
}

int	ensure_params_amount(t_parser_ctx *ctx, char **args, int amount)
{
	if (ft_matrix_len(args + 1) < amount)
		throw_parse_err(ctx, safe_ft_strjoin("Missing params: ", args[0],
				throw_sys_error, "splitting error message"));
	return (1);
}
