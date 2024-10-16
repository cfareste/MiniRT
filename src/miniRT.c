#include "libft.h"
#include "MLX42.h"
#include "scene.h"
#include "render/render.h"

void	destroy(t_scene *scene)
{
	free(scene->ambient_light);
	free(scene->camera);
	free_lights(scene->lights);
	free_figures(scene->figures);
}

// TODO: Create a loader
void	show_scene(t_scene *scene)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	(void) scene;
	mlx = mlx_init(1000, 1000, "Test", true);
	image = mlx_new_image(mlx, 1000, 1000);
	render_scene(scene, image);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments!\n"), EXIT_FAILURE);
	create_scene(&scene, argv[1]);
	show_scene(&scene);
	return (destroy(&scene), EXIT_SUCCESS);
}
