/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:31:15 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/22 22:23:08 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(int fd, char *str, int *count)
{
	while (*str && *count > -1)
	{
		ft_putchar(fd, str, count);
		str++;
	}
	return (*count);
}
