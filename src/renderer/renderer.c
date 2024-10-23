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

void	compute_diffuse(t_ray *shadow_ray, t_hit_record *hit_record, \
							t_light *light, t_color *color)
{
	float	strength;

	strength = dot(&shadow_ray->direction, &hit_record->normal);
	if (strength < 0.0)
		strength = 0.0;
	color->red += strength * light->brightness * light->color.red * 0.5;
	color->green += strength * light->brightness * light->color.green * 0.5;
	color->blue += strength * light->brightness * light->color.blue * 0.5;
}

void	compute_specular(t_scene *scene, t_ray *shadow_ray, \
							t_hit_record *hit_record, t_light *light, \
							t_color *color)
{
	float			strength;
	t_coordinates	reflected;

	reflect(&shadow_ray->direction, &hit_record->normal, &reflected);
	strength = dot(&scene->camera->front, &reflected);
	if (strength < 0.0)
		strength = 0.0;
	strength = pow(strength, 256);
	color->red += strength * light->brightness * light->color.red * 0.5;
	color->green += strength * light->brightness * light->color.green * 0.5;
	color->blue += strength * light->brightness * light->color.blue * 0.5;
}

void	check_lights(t_hit_record *hit_record, t_scene *scene, t_color *color)
{
	t_ray		shadow_ray;
	t_light		*light;
	t_figure	*figure;
	float		distance;

	light = scene->lights;
	while (light)
	{
		set_shadow_ray(hit_record, &shadow_ray, light);
		figure = scene->figures;
		while (figure)
		{
			if (figure != hit_record->figure
				&& figure->hit(figure, &shadow_ray, &distance))
				break ;
			figure = figure->next;
		}
		if (!figure)
		{
			compute_diffuse(&shadow_ray, hit_record, light, color);
			compute_specular(scene, &shadow_ray, hit_record, light, color);
		}
		light = light->next;
	}
}

int	process_lighting(t_scene *scene, t_hit_record *hit_record)
{
	t_color	light_color;
	t_color	final_color;

	light_color.red = 0.0;
	light_color.green = 0.0;
	light_color.blue = 0.0;
	if (!hit_record->figure)
		return (get_sky_color(scene));
	apply_ambient_lighting(scene->ambient_light, &light_color);
	check_lights(hit_record, scene, &light_color);
	final_color.red = light_color.red * hit_record->figure->color.red;
	final_color.green = light_color.green * hit_record->figure->color.green;
	final_color.blue = light_color.blue * hit_record->figure->color.blue;
	// final_color.red = 0.5 * (hit_record->normal.x + 1);
	// final_color.green = 0.5 * (hit_record->normal.y + 1);
	// final_color.blue = 0.5 * (hit_record->normal.z + 1);
	return (get_color_value(&final_color));
}

void	render_scene(t_window *window)
{
	uint32_t		i;
	uint32_t		j;
	int				color;
	t_hit_record	hit_record;

	if (is_render_finished(&window->renderer))
		return ;
	i = 0;
	config_viewport(window->scene.camera, &window->scene.camera->viewport,
		window->size.width, window->size.height);
	while (!is_render_finished(&window->renderer) && i < window->image->width)
	{
		j = 0;
		while (!is_render_finished(&window->renderer)
			&& j < window->image->height)
		{
			ft_bzero(&hit_record, sizeof(t_hit_record));
			check_collisions(&window->scene, &hit_record, i, j);
			color = process_lighting(&window->scene, &hit_record);
			mlx_put_pixel(window->image, i, j, color);
			j++;
		}
		i++;
	}
}
