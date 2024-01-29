/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:24:20 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/29 18:08:22 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	f_check(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		file_error();
	while (str[i])
		i++;
	if (str[i - 1] != 'f')
		file_error();
}

int	ft_line_cnt(char *file_name)
{
	int		fd;
	int		row;
	char	*tmp_line;

	row = 0;
	fd = open(file_name, O_RDWR);
	if (fd < 0)
		ft_error(errno);
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (!tmp_line)
			break ;
		row++;
		if (!is_nl(tmp_line))
			break ;
		free(tmp_line);
	}
	if (tmp_line != NULL)
		free(tmp_line);
	close(fd);
	return (row);
}

void	map_free(int **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	**parsing(char *file_name, int *col_size, int *row_size)
{
	int	fd;
	int	line_cnt;
	int	**map;

	f_check(file_name);
	filename_check(file_name);
	line_cnt = ft_line_cnt(file_name);
	if (line_cnt == 0)
		map_error();
	fd = open(file_name, O_RDWR);
	if (fd < 0)
		ft_error(errno);
	map = read_map(fd, line_cnt, col_size, row_size);
	return (map);
}
