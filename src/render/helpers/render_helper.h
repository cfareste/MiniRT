#pragma once

#include "render/scene/figure/figure.h"
#include "render/render.h"

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure);

int		is_render_finished(t_render *render);

void	set_render_finish(t_render *render, int value);

int		is_render_finished(t_render *render);

void	set_render_finish(t_render *render, int value);
