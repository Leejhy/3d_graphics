/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:23:29 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/29 18:19:32 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long long	ft_atoll(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!('0' <= *str && *str <= '9'))
		map_error();
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (!(*str == ' ' || *str == '\t'))
	{
		if (*str == '\0' || *str == '\n')
			return (sign * result);
		map_error();
	}
	return (sign * result);
}

char	**get_map(int fd, int *line_cnt)
{
	char	**map;
	char	*tmp;
	int		i;

	i = 1;
	map = malloc(sizeof(char *) * (*line_cnt + 1));
	if (!map)
		malloc_failed();
	while (*line_cnt)
	{
		tmp = get_next_line(fd);
		if (!check_ln(tmp))
			free(tmp);
		else
			break ;
		*line_cnt -= 1;
	}
	map[0] = tmp;
	while (i < *line_cnt)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	**make_coordinate(int x_cnt, int y_cnt)
{
	int	**coor;
	int	i;

	i = 0;
	coor = malloc(sizeof(int *) * (y_cnt + 1));
	if (!coor)
		malloc_failed();
	while (i < y_cnt)
	{
		coor[i] = malloc(sizeof(int) * x_cnt);
		if (!coor[i])
			malloc_failed();
		i++;
	}
	coor[i] = NULL;
	return (coor);
}

int	**map_to_coordinate(char **map, int x_cnt, int y_cnt)
{
	char		*tmp_line;
	int			**coor;
	int			i;
	int			j;

	i = 0;
	coor = make_coordinate(x_cnt, y_cnt);
	while (i < y_cnt)
	{
		tmp_line = map[i];
		j = 0;
		while (*tmp_line && *tmp_line != '\n')
		{
			while (*tmp_line && is_sep(*tmp_line, " \t"))
				tmp_line++;
			if (*tmp_line != '\0' && *tmp_line != '\n')
				coor[i][j] = ft_atoll(tmp_line);
			while (*tmp_line && !is_sep(*tmp_line, " \t"))
				tmp_line++;
			j++;
		}
		i++;
	}
	return (coor);
}

int	**read_map(int fd, int line_cnt, int *col_size, int *row_size)
{
	int		col_cnt;
	char	**map;
	int		**coor;
	int		i;

	i = 0;
	map = get_map(fd, &line_cnt);
	while (!check_ln(map[i]))
		i++;
	col_cnt = ft_col_cnt(map[i], " \t");
	*col_size = col_cnt;
	while (!check_ln(map[line_cnt - 1]))
		line_cnt--;
	*row_size = line_cnt;
	check_valid_map(map, col_cnt, line_cnt);
	coor = map_to_coordinate(map, col_cnt, line_cnt);
	map_frees(map);
	return (coor);
}
