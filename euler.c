/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Euler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:29:49 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/15 22:33:17 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void	euler_x(float *old_y, float *old_z, double angle)
{//애네들 각 바꿔야 하긴함 처음에 축이 뒤집어져있어서
	float	y;
	float	z;
	float	new_y;
	float	new_z;

	y = *old_y;
	z = *old_z;
	new_y = y * cos(angle) - z * sin(angle);
	new_z = y * sin(angle) + z * cos(angle);
	*old_y = new_y;
	*old_z = new_z;
}

void	euler_y(float *old_x, float *old_z, double angle)
{
	float	x;
	float	z;
	float	new_x;
	float	new_z;

	x = *old_x;
	z = *old_z;
	new_x = cos(angle) * x - sin(angle) * z;
	new_z = sin(angle) * x + cos(angle) * z;
	*old_x = x;
	*old_z = z;
}

void	euler_z(float *old_x, float *old_y, double angle)
{
	float	x;
	float	y;
	float	new_x;
	float	new_y;

	x = *old_x;
	y = *old_y;
	new_x = cos(angle) * x - sin(angle) * y;
	new_y = sin(angle) * x + cos(angle) * y;
}
