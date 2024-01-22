/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:20:48 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/22 18:14:34 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda(float start_x, float start_y, float end_x, float end_y, t_data *img, int *map)
{
	t_dda	dda;
	int		i;
	
	i = 0;
	start_x -= 515;
	start_y -= 350;
	end_x -= 515;
	end_y -= 350;
	ro_matrix(&start_x, &start_y);
	ro_matrix(&end_x, &end_y);
	start_x += 515;
	start_y += 350;
	end_y += 350;
	end_x += 515;
	dda.dx = end_x - start_x;
	dda.dy = end_y - start_y;
	if (fabsf(dda.dx) > fabsf(dda.dy))//math.c
		dda.base = fabsf(dda.dx);
	else
		dda.base = fabsf(dda.dy);
	dda.inc_x = dda.dx / dda.base;
	dda.inc_y = dda.dy / dda.base;
	while (i <= dda.base)
	{
		// my_mlx_pixel_put(img, dot_x, dot_y, create_trgb(0, 255, 255, 255));
		my_mlx_pixel_put(img, start_x, start_y, create_trgb(0, 255, 255, 255));
		start_x = start_x + dda.inc_x;
		start_y = start_y + dda.inc_y;
		i++;
	}
 }
 