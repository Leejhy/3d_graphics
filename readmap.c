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
		ft_error();
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != ' ')//널, 공백이면 실행되면 안됨
	{
		if (*str == '\0')
			return (sign * result);
		ft_error();
	}
	return (sign * result);
}

char	**get_map(int fd, int line_cnt)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (line_cnt + 1));
	if (!map)
		malloc_failed();
	while (i < line_cnt)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	**read_map(int fd, int line_cnt)
{
	int		word_cnt;
	char	**map;

	map = get_map(fd, line_cnt);
	word_cnt = ft_word_cnt(map[i], ' ');
}
