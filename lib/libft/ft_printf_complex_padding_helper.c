/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_complex_padding_helper.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:52:44 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/22 22:22:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_sign_flag_group(t_state *state)
{
	if (state->num >= 0)
	{
		if (state->force_sign)
			ft_putstr(state->fd, "+", &state->count);
		else if (state->empty_sign)
			ft_putstr(state->fd, " ", &state->count);
	}
	else
	{
		ft_putstr(state->fd, "-", &state->count);
		state->num *= -1;
	}
}

static void	print_hex_prefix(t_state *state)
{
	char	*prefix;

	if (state->num > 0 && state->count != -1 && state->hex_prefix)
	{
		prefix = "0x";
		if (*state->s == 'X')
			prefix = "0X";
		ft_putstr(state->fd, prefix, &state->count);
	}
}

static void	print_value_prefix(t_state *state)
{
	if (*state->s == 'i' || *state->s == 'd')
		handle_sign_flag_group(state);
	else if (is_hex_spec(*state->s))
		print_hex_prefix(state);
}

void	print_complex_padding_left(t_state *state)
{
	if (state->precision > state->buffer_len)
		state->precision_len = state->precision - state->buffer_len;
	if (state->precision == 0 && state->num == 0)
		state->buffer_len = 0;
	if ((state->force_sign || state->empty_sign || state->num < 0)
		&& *state->s != 'u' && !is_hex_spec(*state->s))
		state->buffer_len++;
	if (is_hex_spec(*state->s) && state->hex_prefix && state->num > 0)
		state->buffer_len += 2;
	if (state->padding_char == '0' && state->precision > -1)
		state->padding_char = ' ';
	if ((!state->justify_left && state->padding_char == ' ')
		|| (state->padding_char == '0' && state->precision > -1))
		print_padding(state, state->buffer_len + state->precision_len);
	print_value_prefix(state);
	if (!state->justify_left && state->padding_char == '0')
		print_padding(state, state->buffer_len + state->precision_len);
	if (state->precision > -1)
		print_precision(state, state->precision_len);
}
