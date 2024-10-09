/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:43:45 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/10 14:24:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *) haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *) haystack + i);
		i++;
	}
	return (0);
}

char	*ft_strrstr(const char *haystack, const char *needle)
{
	ssize_t	i;
	size_t	j;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *) haystack);
	i = ft_strlen(haystack) - 1;
	needle_len = ft_strlen(needle) - 1;
	while (i >= 0)
	{
		j = 0;
		while (needle_len >= j && haystack[i - j] == needle[needle_len - j])
			j++;
		if (needle_len < j)
			return ((char *) haystack + i);
		i--;
	}
	return (0);
}
