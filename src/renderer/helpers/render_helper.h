#ifndef RENDER_HELPER_H
# define RENDER_HELPER_H

# include "figure.h"
# include "renderer/renderer.h"

int		get_sky_color(t_scene *scene);

void	apply_ambient_lighting(t_light *ambient, t_color *res);

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure);

void
	set_shadow_ray(t_hit_record *hit_record, t_ray *shadow_ray, t_light *light);

#endif
