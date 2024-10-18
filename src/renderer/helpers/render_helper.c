#include "render_helper.h"

int	get_color(t_figure *figure)
{
	t_color	*figure_color;
	int		color;

	if (!figure)
		return (0xD6EAF8FF);
	figure_color = &figure->color;
	color = (int) (figure_color->red * 255) << 24 | (int) (figure_color->green * 255) << 16 | \
		(int) (figure_color->blue * 255) << 8 | 0xFF;
	return (color);
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
