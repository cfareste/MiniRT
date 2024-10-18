#include "renderer.h"
#include "libft.h"
#include "math.h"
#include "shared/color/color.h"
#include "helpers/render_helper.h"

void	config_viewport(t_camera *camera, t_viewport *vp, int width, int height)
{
	float	focal_distance;

	vp->height = 2.0;
	vp->width = (width * vp->height) / height;
	vp->x_unit = vp->width / width;
	vp->y_unit = vp->height / height;
	focal_distance = 1.0 / tan((camera->fov * 0.5) * M_PI / 180);
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

void	init_ray(t_ray *ray, t_camera *camera, int i, int j)
{
	t_coordinates	viewport_coords;

	ray->bounds.min = 0.01;
	ray->bounds.max = FLT_MAX;
	ray->origin.x = camera->position.x;
	ray->origin.y = camera->position.y;
	ray->origin.z = camera->position.z;
	viewport_coords.x = camera->viewport.start.x + \
		(camera->right.x * camera->viewport.x_unit * i) - \
		(camera->up.x * camera->viewport.y_unit * j);
	viewport_coords.y = camera->viewport.start.y + \
		(camera->right.y * camera->viewport.x_unit * i) - \
		(camera->up.y * camera->viewport.y_unit * j);
	viewport_coords.z = camera->viewport.start.z + \
		(camera->right.z * camera->viewport.x_unit * i) - \
		(camera->up.z * camera->viewport.y_unit * j);
	ray->direction.x = viewport_coords.x - camera->position.x;
	ray->direction.y = viewport_coords.y - camera->position.y;
	ray->direction.z = viewport_coords.z - camera->position.z;
	normalize(&ray->direction);
}

void	check_collisions(t_scene *scene, t_hit_record *hit_record, int i, int j)
{
	t_ray		ray;
	t_figure	*figure;

	hit_record->distance = FLT_MAX;
	figure = scene->figures;
	init_ray(&ray, scene->camera, i, j);
	while (figure)
	{
		if (figure->hit(figure, &ray, &hit_record->distance))
			set_hit_record(hit_record, &ray, figure);
		figure = figure->next;
	}
}

void	render_scene(t_window *window)
{
	uint32_t		i;
	uint32_t		j;
	t_hit_record	hit_record;

	if (is_render_finished(&window->renderer))
		return ;
	i = 0;
	config_viewport(window->scene.camera, &window->scene.camera->viewport,
		window->size.width, window->size.height);
	while (i < window->image->width)
	{
		j = 0;
		while (j < window->image->height && !is_render_finished(&window->renderer))
		{
			ft_bzero(&hit_record, sizeof(t_hit_record));
			check_collisions(&window->scene, &hit_record, i, j);
			mlx_put_pixel(window->image, i, j, get_color(hit_record.figure));
			j++;
		}
		i++;
	}
	set_render_finish(&window->renderer, 1);
	ft_printf("SALGOOO!!!");
}
