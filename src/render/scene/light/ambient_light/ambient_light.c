#include "libft.h"
#include "utils/utils.h"
#include "../light.h"

int	set_ambient_light(char **parts, t_light **light)
{
	if (*light)
		throw_error("Multiple ambient lights are not allowed");
	if (!parts[1] || !parts[2])
		throw_error("Missing ambient light params");
	*light = ft_calloc(1, sizeof(t_light));
	if (!*light)
		throw_sys_error("trying to allocate ambient light");
	(*light)->type = AMBIENT_LIGHT_ID;
	(*light)->brightness = ft_atod(parts[1], throw_sys_error, "ft_atod");
	set_color(parts[2], &(*light)->color);
	if ((*light)->brightness > 1.0 || (*light)->brightness < 0.0)
		throw_error("Invalid brightness param for ambient light");
	return (1);
}

int	get_sky_color(t_light *ambient_light)
{
	t_color	sky_color;

	sky_color.red = (0xD6 / (float)255) * ambient_light->brightness;
	sky_color.green = (0xEA / (float)255) * ambient_light->brightness;
	sky_color.blue = (0xF8 / (float)255) * ambient_light->brightness;
	sky_color.alpha = 1.0;
	return (get_color_value(&sky_color));
}
