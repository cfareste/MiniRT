#ifndef RENDER_HELPER_H
# define RENDER_HELPER_H

# include "figure.h"
# include "renderer/renderer.h"

int		get_color(t_figure *figure);

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure);

int		is_render_finished(t_renderer *renderer);

void	set_render_finish(t_renderer *renderer, int value);

#endif