/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:19:35 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/23 22:49:47 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_dda(t_dda *dda, t_coord coord, t_xyz xyz)
{
	float	end_x;
	float	end_y;//이거 구조체 멤버변수로 만들까 고민해봐

	dda->start_x = coord.offset_x + coord.gap * xyz.x;
	dda->start_y = coord.offset_y + coord.gap * (xyz.y - xyz.z);
	//얘도 z값이 영향줘야하고
	end_x = coord.offset_x + coord.gap * (xyz.x + 1);
	end_y = coord.offset_y + coord.gap * (xyz.y - xyz.z);//얘도 z값이 영향줘야돼
	dda->dx = end_x - dda->start_x;
	dda->dy = end_y - dda->start_y;
	if (fabsf(dda->dx) > fabsf(dda->dy))//math.c
		dda->base = fabsf(dda->dx);
	else
		dda->base = fabsf(dda->dy);
	dda->inc_x = fabsf(dda->dx) / dda->base;
	dda->inc_y = fabsf(dda->dy) / dda->base;
}

void	ft_write_pixel(t_data img, t_coord coord)
{
	t_dda dda;
	int	i;
	int	j;

	i = 0;
	while (i < coord.row)
	{
		j = 0;
		while (j < coord.col)
		{
			init_dda(&dda, coord, coord.xyz_map[i][j]);//지금 위처럼 세팅하면 수평선밖에 못그음 생각좀
			dda;
			j++;
		}
		i++;
	}
}

void	dda(float start_x, float start_y, float end_x, float end_y, t_data *img, int *map)
{
	t_dda	dda;
	int		i;
	
	i = 0;
	dda.dx = end_x - start_x;
	dda.dy = end_y - start_y;
	if (fabsf(dda.dx) > fabsf(dda.dy))//math.c
		dda.base = fabsf(dda.dx);
	else
		dda.base = fabsf(dda.dy);
	dda.inc_x = fabsf(dda.dx) / dda.base;
	dda.inc_y = fabsf(dda.dy) / dda.base;
	while (i <= dda.base)
	{
		my_mlx_pixel_put(img, round(start_x), round(start_y), create_trgb(0, 255, 255, 255));
		start_x = start_x + dda.inc_x;
		start_y = start_y + dda.inc_y;
		i++;
	}
 }
 