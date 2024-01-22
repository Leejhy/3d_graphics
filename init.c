/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:58 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/22 21:50:04 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coord_init(t_coord *coord)
{
	coord->width = 1280;//윈도우 중앙x
	coord->height = 800;//윈도우 중앙y
	coord->gap = 25;
	coord->fir_x = (coord->width / 2) - coord->gap * (coord->col / 2);
	coord->fir_y = (coord->height / 2) - coord->gap * (coord->row / 2);
}