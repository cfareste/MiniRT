/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:52:25 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/22 22:17:58 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_string(t_state *state)
{
	char	*str;
	int		str_len;
	int		i;

	i = 0;
	str = va_arg(state->arg_lst, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (state->precision > -1 && str_len > state->precision)
		str_len = state->precision;
	if (!state->justify_left)
		print_padding(state, str_len);
	while (*str && state->count > -1
		&& (state->precision == -1 || i < state->precision))
	{
		ft_putchar(state->fd, str, &state->count);
		str++;
		i++;
	}
	print_padding_right(state, str_len);
}

static void	print_char(t_state *state, char c)
{
	if (!state->justify_left)
		print_padding(state, 1);
	if (state->count != -1)
		ft_putchar(state->fd, &c, &state->count);
	print_padding_right(state, 1);
}

void	parse_char(t_state *state)
{
	char	c;

	c = va_arg(state->arg_lst, int);
	print_char(state, c);
}

void	parse_percent(t_state *state)
{
	print_char(state, '%');
}
