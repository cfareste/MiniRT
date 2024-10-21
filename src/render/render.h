#pragma once
#include "MLX42.h"
#include "shared/coordinates/coordinates.h"
#include "figure/figure.h"
#include "scene/scene.h"
#include "window/window.h"

typedef struct s_hit_record
{
	t_figure		*figure;
	float			distance;
	t_coordinates	point;
	t_coordinates	normal;
}	t_hit_record;

void	render_scene(t_window *window);
