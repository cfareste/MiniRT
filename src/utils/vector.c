#include "utils.h"
#include "math.h"

void	cross(t_coordinates *vec1, t_coordinates *vec2, t_coordinates *res)
{
	res->x = (vec1->y * vec2->z) - (vec1->z * vec2->y);
	res->y = (vec1->z * vec2->x) - (vec1->x * vec2->z);
	res->z = (vec1->x * vec2->y) - (vec1->y * vec2->x);
}

float	dot(t_coordinates *vec1, t_coordinates *vec2)
{
	return ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
}

void	get_axis(t_coordinates *axis, t_pointing direction)
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

void	normalize(t_coordinates *vec)
{
	float	length;

	length = sqrt(dot(vec, vec));
	vec->x = vec->x / length;
	vec->y = vec->y / length;
	vec->z = vec->z / length;
}

void	reflect(t_coordinates *vec, t_coordinates *normal, t_coordinates *res)
{
	float	product;

	product = 2.0 * dot(vec, normal);
	res->x = vec->x - product * normal->x;
	res->y = vec->y - product * normal->y;
	res->z = vec->z - product * normal->z;
	normalize(res);
}
