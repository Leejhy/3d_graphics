/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:24:20 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/18 20:51:06 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	simple_check(char *str)
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
char	*parsing(char *file_name)
{
	char	*map;
	int		fd;

	simple_check(file_name);
	ft_split(file_name);//여기 안에서 에러처리됨 다음줄이 실행되면 무조건 에러 아닌것
	fd = open(file_name, O_RDWR);
	if (fd < 0)
		ft_error(errno);
	map = read_map(fd);
	return (map);
	//read부분~
}

