/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:58 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/29 18:31:17 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coord_init(t_coord *coord)
{
	coord->width = 1280;
	coord->height = 800;
	coord->gap = 25;
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
	int		i;

	i = 0;
	temp_xyz = malloc(sizeof(t_xyz *) * (row + 1));
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
	while ((coord->gap != 5 && coord->gap * (coord->col - 1) > coord->width)
		|| (coord->gap != 5 && coord->gap * (coord->row - 1) > coord->height))
		coord->gap -= 1;
	coord->z_gap = coord->gap / 5;
	while (coord->xyz_map[i])
	{
		j = 0;
		while (j < coord->col)
		{
			coord->xyz_map[i][j].x = coord->gap * j;
			coord->xyz_map[i][j].y = coord->gap * i;
			coord->xyz_map[i][j].z = coord->z_gap * z_map[i][j];
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
			euler_z(&xyz[i][j].x, &xyz[i][j].y, 45.0);
			euler_x(&xyz[i][j].y, &xyz[i][j].z, 35.264);
			j++;
		}
		i++;
	}
	coord->offset_x = coord->width / 2 - xyz[i / 2][j / 2].x;
	coord->offset_y = coord->height / 2 - xyz[i / 2][j / 2].y;
}
