#include "libft.h"
#include "utils.h"
#include "camera.h"

void	set_camera(char **pieces, t_camera *camera)
{
	if (!pieces[1] || !pieces[2] || !pieces[3])
		throw_error("Missing camera params");
	set_coordinates(pieces[1], &camera->position);
	set_coordinates(pieces[2], &camera->orientation);
	camera->fov = ft_atoi(pieces[3]);
}
