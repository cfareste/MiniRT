#include "libft.h"
#include "MLX42.h"
#include "scene/scene.h"
#include "render/starter/starter_bonus.h"
#include "window/window.h"
#include "render/loader/loader.h"

void	destroy(t_window *window)
{

	destroy_rend_loader(&window->render.loader);
	mlx_terminate(window->mlx);
	mlx_delete_texture(window->icon);
	free(window->scene.name);
	free(window->scene.ambient_light);
	free(window->scene.camera);
	free_lights(window->scene.lights);
	free_figures(window->scene.figures);
}

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments!\n"), EXIT_FAILURE);
	ft_bzero(&window, sizeof(t_window));
	create_scene(&window.scene, argv[1]);
	start_window(&window);
	init_render_loader(&window.render.loader, window.mlx);
	start_render(&window);
	mlx_loop(window.mlx);
	return (destroy(&window), EXIT_SUCCESS);
}
