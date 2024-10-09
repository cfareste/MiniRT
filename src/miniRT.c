#include "libft.h"
#include "scene.h"
#include "MLX42.h"

int	main(int argc, char **argv)
{
	t_scene scene;
	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments!"), EXIT_FAILURE);
	create_scene(&scene, argv[1]);
	return (EXIT_SUCCESS);
}
