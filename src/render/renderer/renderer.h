#pragma once

#include "window/window.h"
#include "render/render.h"
#include <pthread.h>

void	render(t_render *render, mlx_t *mlx);

void	stop_render(t_render *render);
