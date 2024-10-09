/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:13:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/04/10 11:21:34 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	create_buffer(int fd, char **buff)
{
	int	read_res;

	read_res = 1;
	*buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buff)
		return (-1);
	read_res = read(fd, *buff, BUFFER_SIZE);
	if (read_res == 0)
		return (-1);
	if (read_res > 0)
		(*buff)[read_res] = '\0';
	return (read_res);
}

static int	fill_buffer(int fd, char **buff)
{
	char	*new_buff;
	int		str_len;
	int		read_res;

	read_res = 1;
	if (!*buff)
	{
		read_res = create_buffer(fd, buff);
		if (read_res == -1)
			return (-1);
	}
	while (line_break_pos(*buff) == -1 && read_res > 0)
	{
		str_len = ft_strlen(*buff);
		new_buff = malloc((str_len + BUFFER_SIZE + 1) * sizeof(char));
		if (!new_buff)
			return (-1);
		ft_strlcpy(new_buff, *buff, str_len + 1);
		free(*buff);
		*buff = new_buff;
		read_res = read(fd, *buff + str_len, BUFFER_SIZE);
		if (read_res > 0)
			(*buff)[str_len + read_res] = '\0';
	}
	return (read_res);
}

static int	clean_buffer(char **buff, int break_pos, int buff_len, char **line)
{
	char	*excess;

	if (break_pos == buff_len - 1)
		free_buffer(buff);
	else
	{
		excess = ft_substr(*buff, break_pos + 1, buff_len);
		if (!excess)
			return (free_buffer(line), 0);
		free(*buff);
		*buff = excess;
	}
	return (1);
}

static char	*get_line_clean_buffer(char **buff, int buff_res)
{
	char	*line;
	int		break_pos;
	int		buff_len;
	int		clean_buffer_res;

	if (**buff == '\0' && buff_res <= 0)
		return (free_buffer(buff), NULL);
	break_pos = line_break_pos(*buff);
	buff_len = ft_strlen(*buff);
	if (break_pos == -1 && buff_res <= 0)
		break_pos = buff_len - 1;
	line = ft_substr(*buff, 0, break_pos + 1);
	if (!line)
		return (NULL);
	clean_buffer_res = clean_buffer(buff, break_pos, buff_len, &line);
	if (!clean_buffer_res)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd, int line_break)
{
	static char	*buff[FOPEN_MAX];
	char		*line;
	int			fill_buff_res;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	fill_buff_res = fill_buffer(fd, &buff[fd]);
	if ((fill_buff_res < 0 || (fill_buff_res == 0 && *buff[fd] == '\0')))
		return (free_buffer(&buff[fd]), NULL);
	line = get_line_clean_buffer(&buff[fd], fill_buff_res);
	if (!line)
		return (free_buffer(&buff[fd]), NULL);
	else if (!line_break)
	{
		tmp = ft_strtrim(line, "\n");
		free(line);
		return (tmp);
	}
	else
		return (line);
}
