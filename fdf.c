/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:31:23 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/22 22:20:03 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
// << 이 부분이 bit 이동하는 부분임.
// | 8 | 8 | 8 | 8 | 
// 32  24  16  8       이런 구조가 있다고 생각하면
// t는 맨 앞 칸에, r은 두 번째 칸에, ...  이렇게 담김
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_write_pixel(t_data img, t_coord coord)
{
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_coord	coord;
	t_data	img;
	t_xyz	xyz_map;
	int		**z_map;

	if (argc != 2)
		args_error();
	z_map = parsing(argv[1], &coord.col, &coord.row); //free 해줘야함
	coord_init(&coord);
	vars_init(&vars, &coord, &img);
	xyz_map_init(&xyz_map, &coord);//모든 xyz좌표를 2차원 구조체 배열로 들고있음
	rotate_init(&coord);
	ft_write_pixel(img, coord);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
