#include "libft.h"
#include "renderer.h"
#include "window/window.h"
#include <unistd.h>

void	render_scene(t_window *window)
{
	(void) window;
	// while (42)
	// {
	// 	usleep(100000);
	// 	ft_printf("Hola\n");
	// }
	mlx_put_pixel(window->image, 0, 0, 1000);
	mlx_put_pixel(window->image, 0, 1, 1000);
	mlx_put_pixel(window->image, 0, 2, 1000);
	mlx_put_pixel(window->image, 0, 4, 1000);
}
