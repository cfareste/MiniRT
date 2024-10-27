#include "libft.h"
#include "utils/utils.h"
#include "scene.h"
#include <fcntl.h>

void	set_scene_from_str(char *line, t_scene *scene)
{
	char	**scene_args;

	scene_args = ft_split_set(line, SPACES_CHARS);
	if (!scene_args)
		throw_sys_error("ft_split");
	else if (!scene_args[0])
		(void) NULL;
	else if (*scene_args[0] == AMBIENT_LIGHT_ID)
		set_ambient_light(scene_args, &scene->ambient_light);
	else if (*scene_args[0] == CAMERA_ID)
		set_camera(scene_args, &scene->camera);
	else if (*scene_args[0] == LIGHT_ID_MANDATORY || *scene_args[0] == LIGHT_ID)
		push_light(scene_args, &scene->lights);
	else if (!push_figure(scene_args, &scene->figures) && *scene_args[0] != '#')
	{
		ft_printff(STDERR_FILENO,
			"Error\nUnknown scene parameter: %s\n", *scene_args);
		exit(EXIT_FAILURE);
	}
	free_matrix(scene_args);
}

void	set_scene_from_fd(int fd, t_scene *scene)
{
	char	*line;

	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		if (*line)
			set_scene_from_str(line, scene);
		free(line);
		line = get_next_line(fd, 0);
	}
}

void	check_scene(t_scene *scene)
{
	t_light	*lights;
	int		mandatory_lights;

	if (!scene->camera)
		throw_error("A camera is needed to start rendering!");
	lights = scene->lights;
	mandatory_lights = 0;
	while (lights && mandatory_lights < 2)
	{
		if (lights->type == LIGHT_ID_MANDATORY)
			mandatory_lights++;
		lights = lights->next;
	}
	if (!scene->ambient_light || !mandatory_lights)
		throw_error("Some mandatory light is missing!");
	else if (mandatory_lights > 1)
		throw_error("Multiple lights for mandatory are not allowed");
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

void	set_scene_from_filename(t_scene *scene, char *filename)
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
	set_scene_from_fd(fd, scene);
	close(fd);
	check_scene(scene);
	print_scene(scene);
}
