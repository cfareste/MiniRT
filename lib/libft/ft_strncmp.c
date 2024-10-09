/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:10:34 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/10 18:29:21 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chrcmp(unsigned char c1, unsigned char c2)
{
	return (c1 - c2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ft_chrcmp(s1[i], s2[i]) == 0
		&& s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (i == n)
		return (0);
	else
		return (ft_chrcmp(s1[i], s2[i]));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (ft_chrcmp(s1[i], s2[i]) == 0
		&& s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (ft_chrcmp(s1[i], s2[i]));
}

int	ft_strnrcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len < n || s2_len < n)
		return (-1);
	i = s1_len - 1;
	j = s2_len - 1;
	while (i >= s1_len - 1 - n
		&& ft_chrcmp(s1[i], s2[j]) == 0
		&& s1[i] != '\0' && s2[j] != '\0')
	{
		j--;
		i--;
	}
	if (i == s1_len - 1 - n)
		return (0);
	else
		return (ft_chrcmp(s1[i], s2[i]));
}
