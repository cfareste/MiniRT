#pragma once
#include "../ray.h"
#include "render/scene/camera/camera.h"

void	set_ray_from_camera(t_ray *ray, t_camera *camera, int i, int j);

void	set_shadow_ray(t_ray *shadow_ray, t_coordinates *origin,
			t_coordinates *light_pos);
