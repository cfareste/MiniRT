/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:52:05 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/22 22:22:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_padding(t_state *state, int len)
{
	int	i;

	if (state->width == -1)
		return ;
	i = 0;
	while (i < state->width - len
		&& state->count > -1)
	{
		ft_putchar(state->fd, &state->padding_char, &state->count);
		i++;
	}
}

void	print_precision(t_state *state, int len)
{
	int	i;

	if (state->precision == -1)
		return ;
	i = 0;
	while (i < len && state->count > -1)
	{
		ft_putstr(state->fd, "0", &state->count);
		i++;
	}
}

void	print_padding_right(t_state *state, int len)
{
	if (state->justify_left)
	{
		state->padding_char = ' ';
		print_padding(state, len);
	}
}
