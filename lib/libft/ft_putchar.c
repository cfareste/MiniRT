/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:06:22 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/22 22:19:42 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int fd, const char *c, int *counter)
{
	if (write(fd, c, 1) == -1)
		*counter = -1;
	else
		(*counter)++;
	return (*counter);
}
