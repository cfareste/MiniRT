#pragma once

#include "../loader.h"

void	paint_progress(t_loader *loader, unsigned int current, unsigned int total);

void	*render_loader_routine(t_loader *loader);