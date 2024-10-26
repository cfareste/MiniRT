#include "libft.h"
#include "color.h"
#include "utils/utils.h"
#include "render/utils/vector/vector.h"

void	set_color(char *params, t_color *color)
{
	char	**color_parts;

	color_parts = ft_split(params, ',');
	if (!color_parts)
		throw_sys_error("ft_split");
	if (!color_parts[0] || !color_parts[1] || !color_parts[2])
		throw_error("Missing color params");
	color->red = ft_atoi(color_parts[0]) / (float) 255;
	color->green = ft_atoi(color_parts[1]) / (float) 255;
	color->blue = ft_atoi(color_parts[2]) / (float) 255;
	if (color->red > 1.0 || color->green > 1.0 || color->blue > 1.0)
		throw_error("Color params must be [0,255]");
	free_matrix(color_parts);
}

int	get_color_value(t_color *color)
{
	if (color->red > 1.0)
		color->red = 1.0;
	if (color->green > 1.0)
		color->green = 1.0;
	if (color->blue > 1.0)
		color->blue = 1.0;
	return ((int)(color->red * 255) << 24 | (int)(color->green * 255) << 16
		| (int)(color->blue * 255) << 8 | 0xFF);
}

void	get_normal_color(t_color *color, t_vector *normal)
{
	color->red = 0.5 * (normal->x + 1);
	color->green = 0.5 * (normal->y + 1);
	color->blue = 0.5 * (normal->z + 1);
}
