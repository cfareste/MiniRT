/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:45 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/09 22:07:12 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exporter_bonus.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include "render/helpers/render_helper_bonus.h"
#include "image/image_bonus.h"
#include "helpers/exporter_helper_bonus.h"
#include "render/loader/helpers/loader_helper/loader_helper_bonus.h"
#include <fcntl.h>
#include <limits.h>

static void	fill_buffer(char *file_buff, t_image *image, int px_amount, int *j)
{
	int		i;
	int		rel_i;
	char	*num_str;

	i = 0;
	rel_i = 0;
	*j = 0;
	while (i < px_amount)
	{
		if (rel_i == 3)
		{
			rel_i = 0;
			write_str(file_buff, "\n", j);
		}
		else if (rel_i < 3)
		{
			num_str = ft_itoa(image->pixels[i]);
			write_str(file_buff, num_str, j);
			free(num_str);
			write_str(file_buff, " ", j);
			rel_i++;
		}
		i++;
	}
}

static void	file_from_image(int fd, t_image *image)
{
	int		px_amount;
	char	*file_buff;
	int		j;

	ft_printff(fd, "P3\n# This is an amethyst miniRT screenshot!\n%d %d\n%d\n",
		image->size.width, image->size.height, 255);
	px_amount = image->size.width * image->size.height;
	file_buff = ft_calloc(1, sizeof(char) * (1 + (px_amount * (4 * 3))));
	if (!file_buff)
		throw_sys_error("Dynamic memory is so funny today :( ");
	px_amount *= 4;
	fill_buffer(file_buff, image, px_amount, &j);
	write(fd, file_buff, j);
	free(file_buff);
	destroy_image(image);
}

void	*export_routine(t_exporter *exporter)
{
	int		fd;
	char	*path;
	double	start_time;

	set_loader_progress(&exporter->render->loader, 0);
	set_loader_total(&exporter->render->loader, 100);
	set_loader_visibility(&exporter->render->loader, 1);
	set_exporter_active(exporter, 1);
	start_time = mlx_get_time();
	path = set_file_name(exporter->render->scene.settings.name,
			".ppm", EXPORT_BASE_DIR);
	if (!is_render_finished(exporter->render))
		return (NULL);
	fd = open(path, O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		throw_sys_error(path);
	file_from_image(fd, image_dup(exporter->render->image,
			&exporter->render->image_mutex));
	set_loader_progress(&exporter->render->loader, 90);
	close(fd);
	printf("FINSHED EXPORTING %s: %f\n\n", path, mlx_get_time() - start_time);
	free(path);
	set_exporter_active(exporter, 0);
	return (NULL);
}

void	export_image(t_exporter *exporter)
{
	if (!is_exporter_active(exporter) && is_render_finished(exporter->render)
		&& pthread_create(&exporter->thread, NULL,
			(void *(*)(void *)) export_routine, exporter) == -1)
		throw_sys_error("creating loader thread");
}

void	init_exporter(t_exporter *exporter, t_render *render)
{
	pthread_mutex_init(&exporter->mutex, NULL);
	exporter->render = render;
}
