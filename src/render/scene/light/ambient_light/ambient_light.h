#pragma once
#include "../light.h"

int	set_ambient_light(char **parts, t_light **light);

int	get_sky_color(t_light *ambient_light);