#include "libft.h"
#include "MLX42.h"
#include "window/window.h"
#include "render/renderer/renderer.h"

void	destroy(t_window *window)
{
	destroy_loader(&window->render.loader);
	mlx_terminate(window->mlx);
	mlx_delete_texture(window->icon);
	free(window->render.scene.name);
	free(window->render.scene.ambient_light);
	free(window->render.scene.camera);
	free_lights(window->render.scene.lights);
	free_figures(window->render.scene.figures);
}

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments!\n"), EXIT_FAILURE);
	ft_bzero(&window, sizeof(t_window));
	set_scene_from_filename(&window.render.scene, argv[1]);
	init_window(&window);
	init_render(&window.render, window.mlx);
	render(&window.render, window.mlx);
	mlx_loop(window.mlx);
	return (destroy(&window), EXIT_SUCCESS);
}
