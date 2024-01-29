
#include "graphics.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_coord	coord;
	t_data	img;
	int		**z_map;

	if (argc != 2)
		args_error();
	z_map = parsing(argv[1], &coord.col, &coord.row);
	coord_init(&coord);
	vars_img_init(&vars, &coord, &img);
	xyz_map_init(&coord, z_map);
	rotate_init(&coord);
	ft_write_pixel(&img, coord);
	xyz_frees(coord.xyz_map, coord.row);
	mlx_key_hook(vars.win, esc_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
