/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:16 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/18 20:28:13 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils_bonus.h"
#include "libft.h"
#include "export.h"
#include "render/loader/helpers/loader_helper/loader_helper_bonus.h"
#include "render/helpers/render_helper_bonus.h"
#include "../helpers/exporter_helper_bonus.h"
#include "render/loader/helpers/loader_helper/loader_helper_bonus.h"
#include "render/loader/loader_bonus.h"
#include <fcntl.h>

t_export	*new_export(t_exporter *exporter)
{
	t_export	*export;
	export = ft_calloc(1, sizeof(t_export));
	if (!export)
		throw_sys_error("Allocating new export");
	export->exporter = exporter;
	export->image = image_dup(exporter->render->image, &exporter->render->image_mutex);
	return (export);
}

static int	fill_buffer(char *file_buff, int px_amount, t_image *image,
				t_loader *loader)
{
	int		iter[3];
	char	*num_str;

	ft_bzero(iter, sizeof(int) * 3);
	set_loader_total(loader, px_amount);
	while (iter[0] < px_amount)
	{
		if (iter[2] == 3)
		{
			iter[2] = 0;
			write_str(file_buff, "\n", iter + 1);
		}
		else if (iter[2] < 3)
		{
			num_str = ft_itoa(image->pixels[iter[0]]);
			write_str(file_buff, num_str, iter + 1);
			free(num_str);
			if (iter[2] < 2)
				write_str(file_buff, " ", iter + 1);
			iter[2]++;
		}
		add_loader_progress(loader);
		iter[0]++;
	}
	return (iter[1]);
}

static void	file_from_image(int fd, t_image *image, t_loader *loader)
{
	int		px_amount;
	char	*file_buff;
	int		j;

	printf("Image: %p\n", image);
	ft_printff(fd, "P3\n# This is an amethyst miniRT screenshot!\n%d %d\n%d\n",
		image->size.width, image->size.height, 255);
	px_amount = image->size.width * image->size.height;
	file_buff = ft_calloc(1, sizeof(char) * (px_amount * 12));
	if (!file_buff)
		throw_sys_error("Dynamic memory is so funny today :( ");
	printf("Allocated: %lu\n", sizeof(char) * (px_amount * 12));
	px_amount *= 4;
	j = fill_buffer(file_buff, px_amount, image, loader);
	write(fd, file_buff, j);
	free(file_buff);
	destroy_image(image);
}

void	*export_routine(t_export *export)
{
	int		fd;
	char	*path;
	double	start_time;

	set_exporter_active(export->exporter, 1);
	set_loader_progress(&export->exporter->render->loader, 0);
	set_loader_total(&export->exporter->render->loader, 100);
	set_loader_visibility(&export->exporter->render->loader, 1);
	if (!is_render_finished(export->exporter->render))
		return (NULL);
	start_time = mlx_get_time();
	path = set_file_name(export->exporter->render->scene.settings.name,
			".ppm", EXPORT_BASE_DIR, 0);
	printf("Exporting %s\n", path);
	fd = open(path, O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		throw_sys_error(path);
	file_from_image(fd, export->image, &export->exporter->render->loader);
	close(fd);
	printf("FINSHED EXPORTING %s: %f\n", path, mlx_get_time() - start_time);
	free(path);
	set_loader_visibility(&export->exporter->render->loader, 0);
	set_exporter_active(export->exporter, 0);
	return (NULL);
}

void	exec_export(t_export *export)
{
	if (pthread_create(&export->exporter->thread, NULL,
			(void *(*)(void *)) export_routine, export) == -1)
		throw_sys_error("creating export thread");
}
