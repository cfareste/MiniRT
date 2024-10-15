#include "libft.h"
#include "scene.h"
#include "MLX42.h"

void	destroy(t_scene *scene)
{
	free(scene->ambient_light);
	free(scene->camera);
	free_lights(scene->lights);
	free_figures(scene->figures);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments!\n"), EXIT_FAILURE);
	create_scene(&scene, argv[1]);
	return (destroy(&scene), EXIT_SUCCESS);
}
