#include "libft.h"
#include "scene.h"
#include "MLX42.h"

int	main(void)
{
	mlx_t *mlx = mlx_init(1000, 1000, "hola", false);

	if (!mlx)
		exit(1);

	mlx_loop(mlx);

	mlx_terminate(mlx);

	return (0);
}
