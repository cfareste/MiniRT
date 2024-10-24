#include "libft.h"
#include "utils/utils.h"
#include "camera.h"

void	set_camera(char **parts, t_camera **camera)
{
	t_coordinates	world_axis;

	if (*camera)
		throw_error("Multiple cameras are not allowed");
	else if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing camera params");
	*camera = ft_calloc(1, sizeof(t_camera));
	if (!*camera)
		throw_sys_error("trying to allocate t_camera");
	set_coordinates(parts[1], &(*camera)->position);
	set_coordinates(parts[2], &(*camera)->front);
	(*camera)->fov = ft_atoi(parts[3]);
	normalize(&(*camera)->front);
	get_axis(&world_axis, UP);
	if (dot(&(*camera)->front, &world_axis) == 1.0)
		get_axis(&world_axis, BACK);
	else if (dot(&(*camera)->front, &world_axis) == -1.0)
		get_axis(&world_axis, FRONT);
	cross(&(*camera)->front, &world_axis, &(*camera)->right);
	normalize(&(*camera)->right);
	cross(&(*camera)->right, &(*camera)->front, &(*camera)->up);
	normalize(&(*camera)->up);
}

void	print_camera(t_camera *camera)
{
	printf("Camera (%p): \n \
		Position: %f, %f, %f \n \
		Front: %f, %f, %f \n \
		Right: %f, %f, %f \n \
		Up: %f, %f, %f \n \
		FOV: %i\n",
		camera,
		camera->position.x, camera->position.y, camera->position.z,
		camera->front.x, camera->front.y, camera->front.z,
		camera->right.x, camera->right.y, camera->right.z,
		camera->up.x, camera->up.y, camera->up.z,
		camera->fov);
}
