#ifndef RENDER_HELPER_H
# define RENDER_HELPER_H

# include "figure.h"
# include "render/render.h"

int		get_sky_color(t_scene *scene);

void	apply_ambient_lighting(t_light *ambient, t_color *res);

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure);

int		is_render_finished(t_render *render);

void	set_render_finish(t_render *render, int value);

int		is_render_finished(t_render *render);

void	set_render_finish(t_render *render, int value);

void	set_shadow_ray(t_hit_record *hit_record,
			t_ray *shadow_ray, t_light *light);

#endif
