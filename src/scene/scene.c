#include "libft.h"
#include "scene.h"
#include "utils.h"
#include "scene/camera/camera.h"
#include "light.h"
#include <fcntl.h>

int	set_scene_attr(char *line, t_scene *scene)
{
	char	**parts;

	parts = ft_split(line, ' ');
	if (!parts)
		throw_sys_error("ft_split");
	if (*parts[0] == AMBIENT_LIGHT_ID)
		set_ambient_light(parts, &scene->ambient_light);
	else if (*parts[0] == CAMERA_ID)
		set_camera(parts, &scene->camera);
	else if (*parts[0] == LIGHT_ID)
		push_light(parts, &scene->lights);
	else if (!push_figure(parts, &scene->figures))
		if (*parts[0] != '#')
			return (free_matrix(parts), 0);
	return (free_matrix(parts), 1);
}

void	set_scene(int fd, t_scene *scene)
{
	char	*line;

	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		if (*line && !set_scene_attr(line, scene))
			throw_error("Unknown element identifier");
		free(line);
		line = get_next_line(fd, 0);
	}
}

void	print_scene(t_scene *scene)
{
	t_light		*lights;
	t_figure	*figures;

	if (scene->ambient_light)
	{
		ft_printf("Ambient ");
		print_light(scene->ambient_light);
	}
	if (scene->camera)
		print_camera(scene->camera);
	lights = scene->lights;
	while (lights)
	{
		print_light(lights);
		lights = lights->next;
	}
	if (scene->figures)
		printf("\nFigures:\n");
	figures = scene->figures;
	while (figures)
	{
		print_figure(figures);
		figures = figures->next;
	}
}

void	check_scene(t_scene *scene)
{
	if (!scene->camera)
		throw_error("A camera is needed to start rendering!");
	else if (!scene->ambient_light && !scene->lights)
		throw_error("Some light is missing!");
}

void	create_scene(t_scene *scene, char *filename)
{
	int	fd;

	if (!correct_file_extension(filename, SCENE_FILE_EXTENSION))
		throw_error("Only .rt files are allowed");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_sys_error(filename);
	ft_bzero(scene, sizeof(t_scene));
	scene->name = get_file_name(filename, SCENE_FILE_EXTENSION);
	if (!scene->name)
		throw_sys_error("trying to allocate scene name");
	set_scene(fd, scene);
	close(fd);
	check_scene(scene);
	print_scene(scene);
}
