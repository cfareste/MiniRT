#include "render.h"
#include "libft.h"
#include "math.h"
#include "shared/color/color.h"

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

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure)
{
	if (hit_record->distance >= ray->bounds.max)
		return ;
	ray->bounds.max = hit_record->distance;
	hit_record->figure = figure;
	hit_record->point.x = ray->origin.x + \
		hit_record->distance * ray->direction.x;
	hit_record->point.y = ray->origin.y + \
		hit_record->distance * ray->direction.y;
	hit_record->point.z = ray->origin.z + \
		hit_record->distance * ray->direction.z;
	figure->normal(figure, &hit_record->point, &hit_record->normal);
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

int	get_color(t_figure *figure)
{
	t_color	*color;
	int		final_color;

	if (!figure)
		return (0xD6EAF8FF);
	color = &figure->color;
	final_color = color->red << 24 | color->green << 16 | color->blue << 8 | 0xFF;
	return (final_color);	
}

void	render_scene(t_scene *scene, mlx_image_t *image, int width, int height)
{
	int				i;
	int				j;
	t_hit_record	hit_record;

	i = 0;
	config_viewport(scene->camera, &scene->camera->viewport, width, height);
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			ft_bzero(&hit_record, sizeof(t_hit_record));
			check_collisions(scene, &hit_record, i, j);
			mlx_put_pixel(image, i, j, get_color(hit_record.figure));
			j++;
		}
		i++;
	}
}
