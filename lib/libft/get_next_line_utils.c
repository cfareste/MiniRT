/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:13:48 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/24 13:13:51 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_break_pos(char *str)
{
	int	i;
	int	str_len;

	if (!str)
		return (-1);
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len && str[i] != '\n')
		i++;
	if (i == str_len)
		return (-1);
	else
		return (i);
}

void	free_buffer(char **buff)
{
	if (!buff || !*buff)
		return ;
	free(*buff);
	*buff = NULL;
}
