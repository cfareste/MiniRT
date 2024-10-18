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

void	mix_light_color(t_color *color, t_light *light, t_color *res)
{
	res->red = color->red * light->brightness * light->color.red;
	res->green = color->green * light->brightness * light->color.green;
	res->blue = color->blue * light->brightness * light->color.blue;
}

void	phong(t_color *ambient, t_color *diffuse, t_color *specular, t_color *res)
{
	(void) diffuse;
	(void) specular;
	res->red = ambient->red; // + diffuse->red + specular->red;
	res->green = ambient->green; // + diffuse->green + specular->green;
	res->blue = ambient->blue; // + diffuse->blue + specular->blue;
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
