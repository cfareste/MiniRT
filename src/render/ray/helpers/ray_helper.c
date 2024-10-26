#include "utils/utils.h"
#include "../ray.h"
#include "render/scene/camera/camera.h"
#include <math.h>

void	set_ray_from_camera(t_ray *ray, t_camera *camera, int i, int j)
{
	t_coordinates	viewport_coords;
	t_coordinates	origin;
	t_coordinates	direction;

	origin.x = camera->position.x;
	origin.y = camera->position.y;
	origin.z = camera->position.z;
	viewport_coords.x = camera->viewport.start.x + \
		(camera->right.x * camera->viewport.x_unit * i) - \
		(camera->up.x * camera->viewport.y_unit * j);
	viewport_coords.y = camera->viewport.start.y + \
		(camera->right.y * camera->viewport.x_unit * i) - \
		(camera->up.y * camera->viewport.y_unit * j);
	viewport_coords.z = camera->viewport.start.z + \
		(camera->right.z * camera->viewport.x_unit * i) - \
		(camera->up.z * camera->viewport.y_unit * j);
	direction.x = viewport_coords.x - camera->position.x;
	direction.y = viewport_coords.y - camera->position.y;
	direction.z = viewport_coords.z - camera->position.z;
	set_ray(ray, &origin, &direction);
}

void	set_shadow_ray(t_ray *shadow_ray, t_coordinates *origin,
			t_coordinates *light_pos)
{
	shadow_ray->origin = *origin;
	shadow_ray->direction.x = light_pos->x - shadow_ray->origin.x;
	shadow_ray->direction.y = light_pos->y - shadow_ray->origin.y;
	shadow_ray->direction.z = light_pos->z - shadow_ray->origin.z;
	shadow_ray->bounds.max = sqrt(dot(&shadow_ray->direction,
				&shadow_ray->direction));
	shadow_ray->bounds.min = 0.01;
	normalize(&shadow_ray->direction);
}
