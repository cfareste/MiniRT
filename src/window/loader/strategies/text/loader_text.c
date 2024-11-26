// TODO: Own text with imgs!!
static void	paint_text(t_load *load, t_size img_size)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (loader_is_alive(load->loader) && i < img_size.width)
	{
		j = 0;
		while (loader_is_alive(load->loader) && j < img_size.height)
		{
			pthread_mutex_lock(&load->loader->img_mutex);
			mlx_put_pixel(load->loader->image, i, j, 0xfffffff);
			pthread_mutex_unlock(&load->loader->img_mutex);
			j++;
		}
		i++;
	}
}