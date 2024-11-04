#include "libft.h"
#include "texture.h"
#include "utils/utils_bonus.h"

void	print_texture(t_bump_map *texture)
{
	char	*format_str;

	if (texture->format == OPENGL)
		format_str = "OpenGL";
	else
		format_str = "DirectX";
	ft_printf("TEXTURE (%s): %p\n", format_str, texture->texture);
}

// TODO: add path context!!
void parse_texture(t_parser_ctx *ctx, t_bump_map *texture, char **str)
{
	texture->filename = str[0];
	if (correct_file_extension(str[0], ".png"))
		texture->texture = mlx_load_png(str[0]);
	else if (correct_file_extension(str[0], ".xpm"))
		*texture->texture = mlx_load_xpm42(str[0])->texture;
	else
		throw_parse_err(ctx, "Only .png & .xpm files are allowed!");
	texture->format = OPENGL;
	if (str[1] && ft_strcmp(str[1], "directx") == EQUAL_STRINGS)
		texture->format = DIRECTX;
	print_texture(texture);
}
