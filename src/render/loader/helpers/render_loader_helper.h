#pragma once
#include "render/loader/loader.h"
#include <stdbool.h>

unsigned int	get_current(t_loader *loader);

unsigned int	get_total(t_loader *loader);

void			set_loader_visibility(t_loader *loader, bool visible);

void			update_rend_loader(t_loader *loader, unsigned int current);

void			set_rend_loader_total(t_loader *loader, unsigned int total);
