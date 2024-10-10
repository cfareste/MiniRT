#include "libft.h"
#include "color.h"
#include "utils.h"

void	set_color(char *params, t_color *color)
{
	char	**color_pieces;

	color_pieces = ft_split(params, ',');
	if (!color_pieces[0] || !color_pieces[1] || !color_pieces[2])
		throw_error("Missing color params");
	color->red = ft_atoi(color_pieces[0]);
	color->green = ft_atoi(color_pieces[1]);
	color->blue = ft_atoi(color_pieces[2]);
	if (color->red > 255 || color->green > 255 || color->blue > 255)
		throw_error("Color params must be [0,255]");
	free_matrix(color_pieces);
}
