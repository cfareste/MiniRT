#include "render/utils/vector/vector.h"

void	cross(t_vector *vec1, t_vector *vec2, t_vector *res)
{
	res->x = (vec1->y * vec2->z) - (vec1->z * vec2->y);
	res->y = (vec1->z * vec2->x) - (vec1->x * vec2->z);
	res->z = (vec1->x * vec2->y) - (vec1->y * vec2->x);
}

float	dot(t_vector *vec1, t_vector *vec2)
{
	return ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
}

void	multiply_vector_scalar(t_vector *vec, float scalar, t_vector *res)
{
	res->x = vec->x * scalar;
	res->y = vec->y * scalar;
	res->z = vec->z * scalar;
}
