#include "libft.h"
#include "scene.h"
#include "utils.h"
#include "camera.h"
#include "light.h"
#include <fcntl.h>

void	check_file_errors(char *filename)
{
	if (!correct_file_extension(filename, ".rt"))
		throw_error("No .rt file provided");
}

int	set_scene_attr(char *line, t_scene *scene)
{
	char	**pieces;

	pieces = ft_split(line, ' ');
	if (*pieces[0] == AMBIENT_LIGHT_ID)
		set_ambient_light(pieces, &scene->ambient_light);
	else if (*pieces[0] == CAMERA_ID)
		set_camera(pieces, &scene->camera);
	else if (*pieces[0] == LIGHT_ID)
		push_light(pieces, &scene->lights);
	else if (!push_figure(pieces, &scene->figures))
		if (*pieces[0] != '#')
			return (free_matrix(pieces), 0);
	return (free_matrix(pieces), 1);
}

void	set_scene(int fd, t_scene *scene)
{
	char	*line;

	scene->lights = NULL;
	scene->figures = NULL;
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

	ft_printf("Ambient ");
	print_light(&scene->ambient_light);
	print_camera(&scene->camera);
	lights = scene->lights;
	while (lights)
	{
		print_light(lights);
		lights = lights->next;
	}
	figures = scene->figures;
	while (figures)
	{
		print_figure(figures);
		figures = figures->next;
	}
}

// TODO: Check if scene is valid
void	create_scene(t_scene *scene, char *filename)
{
	int	fd;

	check_file_errors(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_sys_error(filename);
	set_scene(fd, scene);
	close(fd);
	print_scene(scene);
}
