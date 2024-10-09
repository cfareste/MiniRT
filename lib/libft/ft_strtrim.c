/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:21:41 by arcanava          #+#    #+#             */
/*   Updated: 2024/07/06 18:34:48 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

static int	included(char c, char const *set)
{
	int		included;
	size_t	i;

	included = 0;
	i = 0;
	while (!included && set[i] != '\0')
		included = set[i++] == c;
	return (included);
}

char	*safe_ft_strtrim(char const *s1, char const *set, void (*f)(int))
{
	char	*res;

	res = ft_strtrim(s1, set);
	if (!res)
		f(ENOMEM);
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	unsigned int	count;
	size_t			count_back;
	size_t			len;
	size_t			str_len;

	if (!set)
		return (ft_strdup(s1));
	if (!s1 || !*s1)
		return (ft_strdup(""));
	count = 0;
	str_len = ft_strlen(s1);
	count_back = 0;
	while (s1[count] != '\0' && included(s1[count], set))
		count++;
	i = str_len - 1;
	while (i > 0 && i > count && included(s1[i], set))
	{
		count_back++;
		i--;
	}
	len = str_len - (count + count_back);
	return (ft_substr(s1, count, len));
}
