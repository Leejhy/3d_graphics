/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:29:56 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/22 21:11:35 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "./gnl/get_next_line.h"

typedef struct s_dda
{
	float	dx;
	float	dy;
	float	base;
	float	inc_x;
	float	inc_y;
}	t_dda;

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

typedef struct s_coord
{
	float	fir_x;
	float	fir_y;
	float	height;
	float	width;
	int		col;
	int		row;
	int		gap;
}	t_coord;

//fdf.c
void	ft_write_pixel(t_data img, t_coord coord);
// void    my_mlx_pixel_put(t_data *data, float x, float y, int color);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
//bresenham.c
// void	Bresenham(int start_x, int start_y, int end_x, int end_y);
// void	Bresenham(float start_x, float start_y, float end_x, float end_y, t_data *img);
void	dda(float start_x, float start_y, float end_x, float end_y, t_data *img);
// void	Bresenham_y(float start_x, float start_y, float end_x, float end_y, t_data *img);
//fdf_utils.c
size_t	ft_strlen(char *str);
//rotation.c
void	euler_x(float *old_y, float *old_z, double angle);
void	euler_y(float *old_x, float *old_z, double angle);
void	euler_z(float *old_x, float *old_y, double angle);
void	ro_matrix(float *old_x, float *old_y);
//parsing.c
void	simple_check(char *str);
int		ft_line_cnt(char *file_name);
int		**parsing(char *file_name, int *col_size, int *row_size);
//read_map.c
int		**read_map(int fd, int line_cnt, int *col_size, int *row_size);
int		**map_to_coordinate(char **map, int x_cnt, int y_cnt);
int		**make_coordinate(int x_cnt, int y_cnt);
char	**get_map(int fd, int *line_cnt);
long long	ft_atoll(const char *str);
//readmap_utils.c
void	check_valid_map(char **map, size_t col_cnt, size_t line_cnt);
int		check_ln(char *str);
//filecheck.c
int		ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_word_cnt(char *str, char sep);
char	*ft_strdup(char *str, char sep);
void	split_frees(char **ptr);
void	ft_split(char *str);
//error.c
void	ft_error(int err);
void	args_error(void);
void	malloc_failed(void);
void	file_error(void);
void	map_error(void);
#endif