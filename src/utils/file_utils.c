/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:47 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/07 13:11:42 by arcanava         ###   ########.fr       */
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

char	*set_file_name(char *filename, char *extension, char *path)
{
	char	*aux;
	char	*new;
	char	*unique_tok;

	unique_tok = ft_ltoa(mlx_get_time() * mlx_get_time());
	if (!unique_tok)
		throw_sys_error("error creating unique token");
	aux = safe_ft_strjoin(filename,
			unique_tok, throw_sys_error, "dynamic memory is broken!");
	free(unique_tok);
	filename = safe_ft_strjoin(aux, extension,
			throw_sys_error, "dynamic memory is broken!");
	free(aux);
	new = safe_ft_strjoin(path, filename,
			throw_sys_error, "dynamic memory is broken!");
	free(filename);
	return (new);
}
