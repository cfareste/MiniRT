#pragma once
#include "render/loader/loader.h"

void			add_loader_progress(t_loader *loader);

unsigned int	get_loader_progress(t_loader *loader);

void			set_loader_progress(t_loader *loader, unsigned int current);

unsigned int	get_loader_total(t_loader *loader);

void			set_loader_total(t_loader *loader, unsigned int total);
