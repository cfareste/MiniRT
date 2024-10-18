#include "math.h"
#include "render_helper.h"

int	get_sky_color(t_scene *scene)
{
	t_color	sky_color;

	sky_color.red = (0xD6 / (float)255) * scene->ambient_light->brightness;
	sky_color.green = (0xEA / (float)255) * scene->ambient_light->brightness;
	sky_color.blue = (0xF8 / (float)255) * scene->ambient_light->brightness;
	sky_color.alpha = 1.0;
	return (get_color_value(&sky_color));
}

void	apply_ambient_lighting(t_light *ambient, t_color *res)
{
	res->red = ambient->brightness * ambient->color.red;
	res->green = ambient->brightness * ambient->color.green;
	res->blue = ambient->brightness * ambient->color.blue;
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

void
	set_shadow_ray(t_hit_record *hit_record, t_ray *shadow_ray, t_light *light)
{
	shadow_ray->origin.x = hit_record->point.x;
	shadow_ray->origin.y = hit_record->point.y;
	shadow_ray->origin.z = hit_record->point.z;
	shadow_ray->direction.x = light->position.x - shadow_ray->origin.x;
	shadow_ray->direction.y = light->position.y - shadow_ray->origin.y;
	shadow_ray->direction.z = light->position.z - shadow_ray->origin.z;
	shadow_ray->bounds.max = sqrt(dot(&shadow_ray->direction, \
		&shadow_ray->direction));
	shadow_ray->bounds.min = 0.01;
	normalize(&shadow_ray->direction);
}
