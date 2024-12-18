/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:01:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/17 22:06:43 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_char(char	**str, char c, void (*f)(char *), char *msg)
{
	char	*new_word;
	int		len;

	len = ft_strlen(*str);
	new_word = ft_calloc(len + 2, sizeof(char));
	if (!new_word)
		return (f(msg));
	ft_strlcpy(new_word, *str, -1);
	new_word[len] = c;
	free(*str);
	*str = new_word;
}

void	push_str(char **s1, char *s2, void (*f)(char *), char *msg)
{
	char	*new_word;
	int		len1;
	int		len2;

	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	new_word = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!new_word)
		return (f(msg));
	ft_strlcpy(new_word, *s1, -1);
	ft_strlcpy(new_word + len1, s2, -1);
	free(*s1);
	*s1 = new_word;
}
