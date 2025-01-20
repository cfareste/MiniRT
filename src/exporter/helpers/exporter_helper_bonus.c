/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_helper_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:09:24 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/20 18:15:23 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exporter_helper_bonus.h"

int	is_exporter_active(t_exporter *exporter)
{
	int	active;

	pthread_mutex_lock(&exporter->mutex);
	active = exporter->active;
	pthread_mutex_unlock(&exporter->mutex);
	return (active);
}

void	set_exporter_active(t_exporter *exporter, int active)
{
	pthread_mutex_lock(&exporter->mutex);
	exporter->active = active;
	pthread_mutex_unlock(&exporter->mutex);
}

void	write_image(int fd, t_export *export, char *buff, int buff_len)
{
	ft_printff(fd,
		"P3\n# This is an amethyst miniRT screenshot!\n%d %d\n%d\n",
		export->image->size.width, export->image->size.height, 255);
	if (write(fd, buff, buff_len) == -1)
		perror("Error\nFailed to write on file");
	close(fd);
}
