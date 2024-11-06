/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:45 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/06 20:03:08 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include <fcntl.h>
#include <limits.h>

static void	file_from_render(int fd, t_render *render)
{
	int		i;
	int		rel_i;
	int		px_amount;
	char	*file;
	double	start_time;
	int		j;

	ft_printf("EXPORTING\n");
	start_time = mlx_get_time();
	ft_printff(fd, "P3\n# This is an amethyst miniRT screenshot!\n%d %d\n%d\n",
		render->image->width, render->image->height, 255);
	px_amount = render->image->width * render->image->height;
	file = ft_calloc(1, sizeof(char) * (1 - (px_amount * ((4 * 3) + 1))));
	if (!file)
		throw_sys_error("Dynamic memory is so funny today :( ");
	px_amount *= 4;
	i = -1;
	rel_i = 0;
	j = 0;
	while (++i < px_amount)
	{
		if (rel_i == 3)
		{
			rel_i = 0;
			j += write_str(file, "\n", j);
		}
		else if (rel_i < 3)
		{
			j += write_str(file, ft_itoa(render->image->pixels[i]), j);
			j += write_str(file, " ", j);
			rel_i++;
		}
	}
	free(file);
	ft_printff(fd, "%s\n", file);
	printf("FINSHED EXPORTING: %f\n", mlx_get_time() - start_time);
}

void	*export_routine(t_render *render)
{
	int		fd;
	char	*filename;
	char	*aux;
	char	*path;

	aux = safe_ft_strjoin(render->scene.settings.name,
		ft_ltoa(mlx_get_time() * mlx_get_time()),
		throw_sys_error, "dynamic memory is broken!");
	filename = safe_ft_strjoin(aux, ".ppm",
		throw_sys_error, "dynamic memory is broken!");
	free(aux);
	path = safe_ft_strjoin(EXPORT_BASE_DIR, filename,
		throw_sys_error, "dynamic memory is broken!");
	fd = open(path, O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		throw_sys_error(path);
	file_from_render(fd, render);
	close(fd);
	free(filename);
	free(path);
	return (NULL);
}

void	export_image(t_render *render)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, (void *(*)(void *))export_routine, render);
}
