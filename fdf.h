/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:29:56 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/18 22:15:17 by junhylee         ###   ########.fr       */
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
//fdf_utils.c
size_t	ft_strlen(char *str);

//euler.c
void	euler_x(float *old_y, float *old_z, double angle);
void	euler_y(float *old_x, float *old_z, double angle);
void	euler_z(float *old_x, float *old_y, double angle);
//parsing.c
void	simple_check(char *str);
int		ft_line_cnt(char *file_name);
char	**parsing(char *file_name);
//read_map.c
char	**read_map(int fd);
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