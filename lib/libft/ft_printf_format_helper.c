/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:52:34 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/28 16:59:52 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_specifier(t_state *state)
{
	if (*state->s == 's')
		parse_string(state);
	else if (*state->s == 'c')
		parse_char(state);
	else if (*state->s == '%')
		parse_percent(state);
	else if (*state->s == 'p')
		parse_pointer(state);
	else if (is_number_spec(*state->s))
		parse_number(state);
	else if (is_hex_spec(*state->s))
		parse_hexadecimal(state);
	else
	{
		state->s--;
		return (0);
	}
	return (1);
}

static void	set_width(t_state *state)
{
	while (ft_isdigit(*state->s))
	{
		state->width *= 10;
		state->width += *state->s - '0';
		state->s++;
	}
	if (state->width > 0)
		state->has_flags = 1;
}

static void	set_precision(t_state *state)
{
	if (*state->s != '.')
		return ;
	state->has_flags = 1;
	state->precision = 0;
	state->s++;
	while (ft_isdigit(*state->s))
	{
		state->precision *= 10;
		state->precision += *state->s - '0';
		state->s++;
	}
}

void	set_flags(t_state *state)
{
	state->s++;
	while (is_flag(*state->s))
	{
		state->has_flags = 1;
		if (*state->s == '#')
			state->hex_prefix = 1;
		else if (*state->s == '+')
			state->force_sign = 1;
		else if (*state->s == ' ')
			state->empty_sign = 1;
		else if (*state->s == '-')
			state->justify_left = 1;
		else if (*state->s == '0')
			state->padding_char = '0';
		state->s++;
	}
}

void	apply_format(t_state *state)
{
	set_flags(state);
	set_width(state);
	set_precision(state);
	parse_specifier(state);
}
