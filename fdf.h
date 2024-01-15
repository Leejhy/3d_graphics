/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:29:56 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/15 22:33:02 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "./libmlx/mlx.h"

//euler.c
void	euler_x(float *old_y, float *old_z, double angle);
void	euler_y(float *old_x, float *old_z, double angle);
void	euler_z(float *old_x, float *old_y, double angle);
#endif