#ifndef RENDER_HELPER_H
# define RENDER_HELPER_H

# include "figure.h"
# include "renderer/renderer.h"

int		get_sky_color(t_scene *scene);

void	mix_light_color(t_color *color, t_light *light, t_color *res);

void	phong(t_color *ambient, t_color *diffuse, t_color *specular, \
			t_color *res);

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure);

#endif