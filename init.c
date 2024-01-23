/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:58 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/23 19:16:37 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coord_init(t_coord *coord)
{
	coord->width = 1280;//윈도우 중앙x
	coord->height = 800;//윈도우 중앙y
	coord->gap = 25;
	coord->offset_x = (coord->width / 2) - coord->gap * (coord->col / 2);
	coord->offset_y = (coord->height / 2) - coord->gap * (coord->row / 2);
}

void	vars_img_init(t_vars *vars, t_coord *coord, t_data *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, coord->width, coord->height, "plz");
	img->img = mlx_new_image(vars->mlx, coord->width, coord->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

t_xyz	**xyz_malloc(int row, int col)
{
	t_xyz	**temp_xyz;
	int	i;

	i = 0;
	temp_xyz = malloc(sizeof(t_xyz *) * (row + 1));//row만큼 malloc t_xyz *malloc하기
	if (temp_xyz == NULL)
		malloc_failed();
	while (i < row)
	{
		temp_xyz[i] = malloc(sizeof(t_xyz) * col);
		i++;
	}
	temp_xyz[i] = NULL;
	return (temp_xyz);
}

void	xyz_map_init(t_coord *coord, int **z_map)
{
	int	i;
	int	j;

	i = 0;
	coord->xyz_map = xyz_malloc(coord->row, coord->col);
	while (coord->xyz_map[i])
	{
		j = 0;
		while (j < coord->col)
		{
			coord->xyz_map[i][j].x = coord->gap * j;
			coord->xyz_map[i][j].y = coord->gap * i;
			coord->xyz_map[i][j].z = z_map[i][j];
			j++;
		}
		i++;
	}
}

void	rotate_init(t_coord *coord)
{
	int		i;
	int		j;
	t_xyz	**xyz;


	i = 0;
	xyz = coord->xyz_map;
	while (xyz[i])
	{
		j = 0;
		while (j < coord->col)
		{
			euler_x(&xyz[i][j].y, &xyz[i][j].z, -35.264);
			euler_z(&xyz[i][j].x, &xyz[i][j].y, -45.0);
			j++;
		}
		i++;
	}
}
