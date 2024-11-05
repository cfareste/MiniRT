/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:47 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/05 16:50:49 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_bonus.h"

int	correct_file_extension(char *filename, char *extension)
{
	size_t	extension_len;
	char	*filename_;

	filename_ = ft_filename(filename);
	extension_len = ft_strlen(extension);
	return (ft_strnrcmp(filename_, extension, extension_len) == EQUAL_STRINGS
		&& ft_strlen(filename_) > extension_len);
}

char	*get_file_name(char *filename, char *extension)
{
	char	**parts;
	char	*name;

	parts = ft_split(filename, '/');
	if (!parts)
		throw_sys_error("ft_split");
	if (!parts || !filename || !extension)
		return (NULL);
	name = parts[ft_stroccurrences(filename, '/')];
	name = ft_substr(name, 0, ft_strlen(name) - ft_strlen(extension));
	if (!name)
		throw_sys_error("ft_substr");
	free_matrix(parts);
	return (name);
}
