
#include "graphics.h"

void	ft_write_pixel(t_data *img, t_coord coord)
{
	t_xyz	**xyz;
	int		i;
	int		j;

	xyz = coord.xyz_map;
	i = 0;
	if (coord.row == 1 && coord.col == 1)
		write_dda(xyz[0][0], xyz[0][0], img, coord);
	while (i < coord.row)
	{
		j = 0;
		while (j < coord.col)
		{
			if (j < coord.col - 1)
				write_dda(xyz[i][j], xyz[i][j + 1], img, coord);
			if (i < coord.row - 1)
				write_dda(xyz[i][j], xyz[i + 1][j], img, coord);
			j++;
		}
		i++;
	}
}

void	set_dda(t_dda *dda, t_xyz xyz, t_xyz next_xyz)
{
	dda->dx = next_xyz.x - xyz.x;
	dda->dy = next_xyz.y - xyz.y;
	dda->start_x = xyz.x;
	dda->start_y = xyz.y;
	if (fabsf(dda->dx) > fabsf(dda->dy))
		dda->dis = fabsf(dda->dx);
	else
		dda->dis = fabsf(dda->dy);
	dda->inc_x = dda->dx / dda->dis;
	dda->inc_y = dda->dy / dda->dis;
}

void	write_dda(t_xyz xyz, t_xyz next_xyz, t_data *img, t_coord coord)
{
	t_dda	dda;
	float	put_x;
	float	put_y;
	float	i;

	i = 0;
	set_dda(&dda, xyz, next_xyz);
	put_x = dda.start_x + coord.offset_x;
	put_y = dda.start_y + coord.offset_y;
	if (!(put_x > coord.width - 1 || put_y > coord.height - 1
			|| put_x < 0 || put_y < 0))
		my_mlx_pixel_put(img, round(put_x), round(put_y),
			create_trgb(0, 255, 255, 255));
	while (i < dda.dis)
	{
		put_x = put_x + dda.inc_x;
		put_y = put_y + dda.inc_y;
		if (!(put_x > coord.width - 1 || put_y > coord.height - 1
				|| put_x < 0 || put_y < 0))
			my_mlx_pixel_put(img, round(put_x), round(put_y),
				create_trgb(0, 255, 255, 255));
		i++;
	}
}
