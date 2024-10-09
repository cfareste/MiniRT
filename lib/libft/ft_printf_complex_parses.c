/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_complex_parses.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:52:54 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/30 12:32:18 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_pointer(t_state *state)
{
	unsigned long long	ptr_val;
	char				buff[sizeof(void *) * 2];
	int					i;
	int					len;

	ptr_val = (unsigned long long) va_arg(state->arg_lst, void *);
	i = 0;
	while (ptr_val > 0)
	{
		buff[i++] = "0123456789abcdef"[ptr_val % 16];
		ptr_val /= 16;
	}
	len = i + 2 + (i == 0);
	if (!state->justify_left)
		print_padding(state, len);
	ft_putstr(state->fd, "0x", &state->count);
	if (i == 0 && state->count != -1)
		ft_putstr(state->fd, "0", &state->count);
	while (i && state->count > -1)
		ft_putchar(state->fd, &buff[--i], &state->count);
	if (state->justify_left)
		print_padding_right(state, len);
}

void	parse_number(t_state *state)
{
	if (*state->s == 'i' || *state->s == 'd')
		state->num = (long) va_arg(state->arg_lst, int);
	else if (*state->s == 'u')
		state->num = (long) va_arg(state->arg_lst, unsigned int);
	else if (*state->s == 'l')
		state->num = (long) va_arg(state->arg_lst, long);
	else
		return ;
	state->buffer_len = count_digits((long) state->num);
	print_complex_padding_left(state);
	if (!(state->num == 0 && state->precision == 0) && state->count > -1)
		ft_putnbr(state->fd, state->num, &state->count);
	print_padding_right(state, state->buffer_len + state->precision_len);
}

static void	print_buffer(t_state *state, char *buff, int i)
{
	if (i == 0 && state->count != -1 && (state->precision != 0))
		ft_putstr(state->fd, "0", &state->count);
	while (i && state->count > -1)
		ft_putchar(state->fd, &buff[--i], &state->count);
}

static void	print_hexadecimal(t_state *state, char *buff, int str_len)
{
	state->buffer_len = str_len;
	if (state->buffer_len == 0)
		state->buffer_len = 1;
	print_complex_padding_left(state);
	print_buffer(state, buff, str_len);
	print_padding_right(state, state->buffer_len + state->precision_len);
}

void	parse_hexadecimal(t_state *state)
{
	char			*buff;
	int				i;
	unsigned int	nbr;

	nbr = va_arg(state->arg_lst, unsigned int);
	state->num = (long) nbr;
	buff = malloc(sizeof(char) * (count_hex_digits(nbr) + 1));
	if (!buff)
	{
		state->count = -1;
		return ;
	}
	i = 0;
	while (nbr > 0)
	{
		if (*state->s == 'X')
			buff[i++] = "0123456789ABCDEF"[nbr % 16];
		else
			buff[i++] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	buff[i] = '\0';
	print_hexadecimal(state, buff, i);
	free(buff);
}
