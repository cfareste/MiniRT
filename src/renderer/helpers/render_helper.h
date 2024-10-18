#ifndef RENDER_HELPER_H
# define RENDER_HELPER_H

# include "figure.h"
# include "renderer/renderer.h"

int		get_color(t_figure *figure);

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure);

#endif