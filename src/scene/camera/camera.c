#include "libft.h"
#include "utils.h"
#include "camera.h"

void	set_camera(char **pieces, t_camera **camera)
{
	if (!pieces[1] || !pieces[2] || !pieces[3])
		throw_error("Missing camera params");
	*camera = ft_calloc(1, sizeof(t_camera));
	if (!*camera)
		throw_sys_error("trying to allocate t_camera");
	set_coordinates(pieces[1], &(*camera)->position);
	set_coordinates(pieces[2], &(*camera)->front);
	(*camera)->fov = ft_atoi(pieces[3]);
}

void	print_camera(t_camera *camera)
{
	printf("Camera (%p): %f, %f, %f | %f, %f, %f | %i\n",
		camera,
		camera->position.x, camera->position.y, camera->position.z,
		camera->front.x, camera->front.y, camera->front.z,
		camera->fov);
}
