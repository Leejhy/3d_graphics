/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:23:29 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/18 22:21:45 by junhylee         ###   ########.fr       */
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
	if (*str != ' ')//100-1 이런거막아줌
	{
		if (*str == '\0' || *str == '\n')
			return (sign * result);
		map_error();
	}
	return (sign * result);
}

char	**get_map(int fd, int line_cnt)
{
	char	**map;
	char	*tmp;
	int		i;

	i = 1;
	map = malloc(sizeof(char *) * (line_cnt + 1));
	if (!map)
		malloc_failed();
	while (line_cnt)
	{
		tmp = get_next_line(fd);
		if (!check_ln(tmp))//맨처음 개행만 스킵
			free(tmp);
		else//개행 아닐때 break 해서 나오고
			break ;
		line_cnt--;
	}
	map[0] = tmp;
	while (i < line_cnt)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	**make_coordinate(char **map, int x_cnt, int y_cnt)
{
	int	i;
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
	char	*tmp_line;
	int	**coor;
	int	i;
	int	j;

	i = 0;
	j = 0;
	coor = make_coordinate(map, x_cnt, y_cnt);
	while (i < y_cnt)
	{
		tmp_line = map[i];
		while (*tmp_line && *tmp_line != '\n')
		{
			while (*tmp_line && *tmp_line == ' ')
				tmp_line++;
			if (*tmp_line != '\0' && *tmp_line != '\n')
			{
				nb = ft_atoll(tmp_line);
				map[i][j] = nb;
			}
			while (*tmp_line && *tmp_line != ' ')
				str++;
			j += 1;
		}
		i++;
	}
}

int	**read_map(int fd, int line_cnt)
{
	int		col_cnt;
	char	**map;
	int		**coor;
	map = get_map(fd, line_cnt);
	col_cnt = ft_word_cnt(map[i], ' ');
	check_valid_map(map, col_cnt, line_cnt);//map size, 이상한 인자 확인
	coor = map_to_coordinate(map, col_cnt, line_cnt)
	return (coor);
}
