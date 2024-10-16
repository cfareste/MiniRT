#include "libft.h"
#include "MLX42.h"
#include "scene.h"
#include "render/render.h"
#include "window/window.h"

void	destroy(t_scene *scene)
{
	free(scene->ambient_light);
	free(scene->camera);
	free_lights(scene->lights);
	free_figures(scene->figures);
	free(scene->name);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments!\n"), EXIT_FAILURE);
	create_scene(&scene, argv[1]);
	start_window(&scene);
	return (destroy(&scene), EXIT_SUCCESS);
}
