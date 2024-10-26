#include "render_helper.h"

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

int	is_render_finished(t_render *render)
{
	int	finished;

	pthread_mutex_lock(&render->render_mutex);
	finished = render->finished;
	pthread_mutex_unlock(&render->render_mutex);
	return (finished);
	return (0);
}

void	set_render_finish(t_render *render, int value)
{
	pthread_mutex_lock(&render->render_mutex);
	render->finished = value;
	pthread_mutex_unlock(&render->render_mutex);
}
