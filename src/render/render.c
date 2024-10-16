#include "render.h"
#include "libft.h"

void	config_viewport(t_camera *camera, t_viewport *vp, int width, int height)
{
	vp->height = 9.0;
	vp->width = (width * vp->height) / height;
	vp->x_unit = vp->width / width;
	vp->y_unit = vp->height / height;
	vp->center.x = camera->position.x + 2.0 * camera->front.x;
	vp->center.y = camera->position.y + 2.0 * camera->front.y;
	vp->center.z = camera->position.z + 2.0 * camera->front.z;
	vp->start.x = vp->center.x - (vp->width * camera->right.x / 2.0) + \
		(vp->height * camera->up.x / 2.0);
	vp->start.y = vp->center.y - (vp->width * camera->right.y / 2.0) + \
		(vp->height * camera->up.y / 2.0);
	vp->start.z = vp->center.z - (vp->width * camera->right.z / 2.0) + \
		(vp->height * camera->up.z / 2.0);
}

void	render_scene(t_scene *scene, mlx_image_t *image, int width, int height)
{
	int				i;
	int				j;
	t_hit_record	hit_record;

	i = 0;
	ft_bzero(&hit_record, sizeof(t_hit_record));
	config_viewport(scene->camera, &scene->camera->viewport, width, height);
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			mlx_put_pixel(image, i, j, 0xFFFF00FF);
			j++;
		}
		i++;
	}
}
