#include "libft.h"
#include "../../loader.h"

int	get_bar_total_width(int window_width)
{
	return (ft_clamp(window_width / 2, 10, LOADER_WIDTH_MAX));
}

int	get_bar_width(int window_width, double current, double total)
{
	return (get_bar_total_width(window_width) * (current / total));
}

int	get_bar_height(int window_height)
{
	return (ft_clamp(window_height / 20, 2, LOADER_HEIGHT_MAX));
}
