/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:16 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:36:19 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include "../helpers/exporter_helper_bonus.h"
#include "window/loader/strategies/progress/loader_progress.h"
#include <fcntl.h>

t_export	*new_export(t_exporter *exporter)
{
	t_export	*export;

	export = ft_calloc(1, sizeof(t_export));
	if (!export)
		throw_sys_error("Allocating new export");
	export->exporter = exporter;
	export->image = image_dup(exporter->render->image,
			&exporter->render->image_mutex);
	return (export);
}

static int	fill_buffer(char *file_buff, int px_amount, t_export *export)
{
	int		iter[3];
	char	*num_str;

	ft_bzero(iter, sizeof(int) * 3);
	while (is_exporter_active(export->exporter) && iter[0] < px_amount)
	{
		loader_add_progress(export->exporter->loader);
		if (iter[2] == 3)
		{
			iter[2] = 0;
			write_str(file_buff, "\n", iter + 1);
		}
		else if (iter[2] < 3)
		{
			num_str = safe_ft_ltoa(export->image->pixels[iter[0]],
					throw_sys_error, "exporting image");
			write_str(file_buff, num_str, iter + 1);
			free(num_str);
			if (iter[2] < 2)
				write_str(file_buff, " ", iter + 1);
			iter[2]++;
		}
		iter[0]++;
	}
	return (iter[1]);
}

static void	file_from_export(char *path, t_export *export)
{
	int		px_amount;
	char	*file_buff;
	int		j;
	int		fd;

	px_amount = export->image->size.width * export->image->size.height;
	file_buff = ft_calloc(1, sizeof(char) * (px_amount * 12));
	if (!file_buff)
		throw_sys_error("Dynamic memory is so funny today :( ");
	px_amount *= 4;
	loader_set_total(export->exporter->loader, px_amount);
	j = fill_buffer(file_buff, px_amount, export);
	if (is_exporter_active(export->exporter))
	{
		fd = open(path, O_CREAT | O_WRONLY, 0644);
		if (fd != -1)
			write_image(fd, export, file_buff, j);
		else
			perror("Error\nFailed to export file");
	}
	free(file_buff);
	destroy_image(export->image);
}

void	*export_routine(t_export *export)
{
	char	*path;
	double	start_time;

	set_exporter_active(export->exporter, 1);
	start_time = mlx_get_time();
	path = set_file_name(export->exporter->render->scene.settings.name,
			".ppm", EXPORT_BASE_DIR, 0);
	printf("Exporting %s\n", path);
	loader_show(export->exporter->loader, BAR, LOADER_SIZE_MINI);
	file_from_export(path, export);
	if (is_exporter_active(export->exporter))
		printf("FINSHED EXPORTING %s: %f\n", path,
			mlx_get_time() - start_time);
	loader_hide(export->exporter->loader);
	free(path);
	set_exporter_active(export->exporter, 0);
	free(export);
	return (NULL);
}

void	exec_export(t_export *export)
{
	if (export->exporter->thread)
		pthread_join(export->exporter->thread, NULL);
	if (pthread_create(&export->exporter->thread, NULL,
			(void *(*)(void *)) export_routine, export) == -1)
		throw_sys_error("creating export thread");
}
