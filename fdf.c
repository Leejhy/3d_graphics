/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:31:23 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/18 20:57:51 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

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
	// void	*mlx;
	// void	*win;
	char	*map;
	// t_data	img;

	if (argc != 2)
		args_error();
	map = parsing(argv[1]);//free 해줘야함
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 500, 500, "plz");
	// img.img = mlx_new_image(mlx, 500, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	// 							&img.line_length, &img.endian);
	// for (int i = 0; i < 250; i++)
	// {
	// 	my_mlx_pixel_put(&img, i, 0, create_trgb(0,255,0,0));
	// 	my_mlx_pixel_put(&img, 0, i, create_trgb(0,255,0,0));
	// 	my_mlx_pixel_put(&img, i, i, create_trgb(0,255,0,0));
	// }
	// mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	// mlx_loop(mlx);
}
