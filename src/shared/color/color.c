#include "libft.h"
#include "color.h"
#include "utils.h"

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
