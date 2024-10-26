#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include <math.h>

void	get_vector(t_coordinates *final, t_coordinates *start, t_vector *vec)
{
	vec->x = final->x - start->x;
	vec->y = final->y - start->y;
	vec->z = final->z - start->z;
}

void	get_axis(t_vector *axis, t_pointing direction)
{
	if (direction == RIGHT)
		axis->x = 1.0;
	else if (direction == LEFT)
		axis->x = -1.0;
	else
		axis->x = 0.0;
	if (direction == UP)
		axis->y = 1.0;
	else if (direction == DOWN)
		axis->y = -1.0;
	else
		axis->y = 0.0;
	if (direction == FRONT)
		axis->z = -1.0;
	else if (direction == BACK)
		axis->z = 1.0;
	else
		axis->z = 0.0;
}

void	normalize(t_vector *vec)
{
	float	length;

	length = sqrt(dot(vec, vec));
	if (length == 0.0)
		return ;
	vec->x = vec->x / length;
	vec->y = vec->y / length;
	vec->z = vec->z / length;
}

void	reflect(t_vector *vec, t_vector *normal, t_vector *res)
{
	float	product;

	product = 2.0 * dot(vec, normal);
	res->x = vec->x - product * normal->x;
	res->y = vec->y - product * normal->y;
	res->z = vec->z - product * normal->z;
	normalize(res);
}
