#include "libft.h"
#include "utils.h"
#include "coordinates.h"

void	set_coordinates(char *str, t_coordinates *coordinates)
{
	char	**pieces;

	pieces = ft_split(str, ',');
	if (!pieces[0] || !pieces[1] || !pieces[2])
		throw_error("Missing some coordinates param");
	coordinates->x = ft_atod(pieces[0]);
	coordinates->y = ft_atod(pieces[1]);
	coordinates->z = ft_atod(pieces[2]);
	free_matrix(pieces);
}
