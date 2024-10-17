#include "libft.h"
#include "MLX42.h"
#include "scene.h"
#include "render/render.h"
#include "window/window.h"

void	destroy(t_window *window)
{
	mlx_terminate(window->mlx);
	free(window->scene.ambient_light);
	free(window->scene.camera);
	free_lights(window->scene.lights);
	free_figures(window->scene.figures);
	free(window->scene.name);
}

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments!\n"), EXIT_FAILURE);
	create_scene(&window.scene, argv[1]);
	start_window(&window);
	render_scene(&window);
	mlx_loop(window.mlx);
	return (destroy(&window), EXIT_SUCCESS);
}
