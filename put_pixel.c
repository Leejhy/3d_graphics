/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:19:35 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/24 22:47:19 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_set_dda(t_dda *dda, t_coord coord, t_xyz xyz, t_xyz next_xyz)
{
	float	end_x;
	float	end_y;//이거 구조체 멤버변수로 만들까 고민해봐

	dda->start_x = coord.offset_x + xyz.x;
	dda->start_y = coord.offset_y + xyz.y;
	//얘도 z값이 영향줘야하고
	end_x = coord.offset_x + next_xyz.x;
	end_y = coord.offset_y + next_xyz.y;//얘도 z값이 영향줘야돼
	printf("%f %f\n",dda->start_y, end_y);
	printf("================\n");
	dda->dx = end_x - dda->start_x;
	dda->dy = end_y - dda->start_y;
	if (fabsf(dda->dx) > fabsf(dda->dy))//math.c
		dda->base = fabsf(dda->dx);
	else
		dda->base = fabsf(dda->dy);
	dda->inc_x = fabsf(dda->dx) / dda->base;
	dda->inc_y = fabsf(dda->dy) / dda->base;
}

void	y_set_dda(t_dda *dda, t_coord coord, t_xyz xyz, t_xyz next_xyz)
{
	float	end_x;
	float	end_y;//이거 구조체 멤버변수로 만들까 고민해봐

	dda->start_x = coord.offset_x + xyz.x;//
	dda->start_y = coord.offset_y + xyz.y;
	end_x = coord.offset_x + next_xyz.x;//얘는 예시로 (1, 5) ~ (1, 6)의 선을 긋는 세팅이니까 start x, end x 고정
	end_y = coord.offset_y + next_xyz.y;//y값만 변경
	printf("%f %f\n",dda->start_y, end_y);
	dda->dx = end_x - dda->start_x;
	dda->dy = end_y - dda->start_y;
	if (fabsf(dda->dx) > fabsf(dda->dy))//math.c
		dda->base = fabsf(dda->dx);
	else
		dda->base = fabsf(dda->dy);
	dda->inc_x = fabsf(dda->dx) / dda->base;
	dda->inc_y = fabsf(dda->dy) / dda->base;
}

void	ft_write_pixel(t_data *img, t_coord coord)
{
	t_dda dda;
	int	i;
	int	j;

	i = 0;
	while (i < coord.row)
	{
		j = 0;
		while (j < coord.col)
		{//if 걸어서 dda 마지막줄 세팅하기
			if (j < coord.col - 1)
			{
				x_set_dda(&dda, coord, coord.xyz_map[i][j], coord.xyz_map[i][j + 1]);//지금 위처럼 세팅하면 수평선밖에 못그음
				ft_dda(dda, img, coord);//&img 해서 더블 포인터 아닌지 생각
			}
			if (i < coord.row - 1)
			{
				y_set_dda(&dda, coord, coord.xyz_map[i][j], coord.xyz_map[i + 1][j]);//지금 위처럼 세팅하면 원점 기준 수직선 긋는친구 세팅
				ft_dda(dda, img, coord);
			}
			j++;
		}
		i++;
	}
}

void	ft_dda(t_dda dda, t_data *img, t_coord coord)
{
	t_dda	dda_x;
	t_dda	dda_y;
	int		i;
	
	i = 0;
	float	put_x;
	float	put_y;

	put_x = dda.start_x;
	put_y = dda.start_y;

	while (i <= dda.base)
	{
		if (put_y <= coord.height && put_x <= coord.width)
			my_mlx_pixel_put(img, round(put_x), round(put_y), create_trgb(0, 255, 255, 255));
		put_x = put_x + dda.inc_x;
		put_y = put_y + dda.inc_y;
		i++;
	}
 }
 