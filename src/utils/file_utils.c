/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:47 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 18:31:34 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_bonus.h"
#include <limits.h>

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

char	*set_file_name(char *filename, char *extension, char *path, int version)
{
	char		*aux;
	char		*new;
	char		*name;
	char		*unique_tok;

	if (version > 0)
	{
		unique_tok = ft_ltoa(version);
		if (!unique_tok)
			throw_sys_error("error creating unique token");
	}
	else
		unique_tok = ft_strdup("");
	aux = safe_ft_strjoin(filename,
			unique_tok, throw_sys_error, "dynamic memory is broken!");
	free(unique_tok);
	name = safe_ft_strjoin(aux, extension,
			throw_sys_error, "dynamic memory is broken!");
	free(aux);
	new = safe_ft_strjoin(path, name,
			throw_sys_error, "dynamic memory is broken!");
	free(name);
	if (access(new, F_OK) == 0)
		new = set_file_name(filename, extension, path, version + 1);
	return (new);
}
