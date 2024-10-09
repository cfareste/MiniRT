/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:28:29 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/10 18:29:27 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_filename(char *path)
{
	char	*filename;

	if (!path)
		return (NULL);
	filename = ft_strrchr(path, '/');
	if (filename)
		filename++;
	else
		filename = path;
	return (filename);
}
