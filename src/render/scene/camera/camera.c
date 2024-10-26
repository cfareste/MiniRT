#include "libft.h"
#include "utils/utils.h"
#include "camera.h"
#include <math.h>

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

void	set_viewport(t_camera *camera, t_viewport *vp, t_size w_size)
{
	float	focal_distance;

	vp->height = 2.0;
	vp->width = (w_size.width * vp->height) / w_size.height;
	vp->x_unit = vp->width / w_size.width;
	vp->y_unit = vp->height / w_size.height;
	focal_distance = tan((camera->fov * 0.5) * M_PI / 180);
	vp->center.x = camera->position.x + focal_distance * camera->front.x;
	vp->center.y = camera->position.y + focal_distance * camera->front.y;
	vp->center.z = camera->position.z + focal_distance * camera->front.z;
	vp->start.x = vp->center.x - (vp->width * camera->right.x / 2.0) + \
		(vp->height * camera->up.x / 2.0);
	vp->start.y = vp->center.y - (vp->width * camera->right.y / 2.0) + \
		(vp->height * camera->up.y / 2.0);
	vp->start.z = vp->center.z - (vp->width * camera->right.z / 2.0) + \
		(vp->height * camera->up.z / 2.0);
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
