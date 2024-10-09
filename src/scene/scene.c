#include "libft.h"
#include "scene.h"
#include "utils.h"
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
	ft_printf("\"%s\", \"%s\", \"%s\"\n", pieces[0], pieces[1], pieces[2]);
	// if (*pieces[0] == AMBIENT_LIGHT_ID)
	// 	set_ambient_light(line, scene);
	// else
	// 	return (free(pieces), 0);
	scene->camera.id = 'c';
	return (free_matrix(pieces), 1);
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

void	create_scene(t_scene *scene, char *filename)
{
	int	fd;

	check_file_errors(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_sys_error(filename);
	set_scene(fd, scene);
	scene->camera.id = 'c';
	close(fd);
}
