/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:31:23 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/25 18:23:40 by junhylee         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_coord	coord;
	t_data	img;
	int		**z_map;

	if (argc != 2)
		args_error();
	z_map = parsing(argv[1], &coord.col, &coord.row); //free 해줘야함
	coord_init(&coord);
	vars_img_init(&vars, &coord, &img);
	xyz_map_init(&coord, z_map);//xyz 구조체 문제인줄 알았는데 아님
	rotate_init(&coord);// 얘가 문제
	ft_write_pixel(&img, coord);
	mlx_key_hook(vars.win, esc_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);//exit hook을 따로 줘야되나?
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
