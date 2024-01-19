#include "fdf.h"

int	check_ln(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\n' && str[i] == '\0')
		return (0);
	return (1);
}

void	check_valid_map(char **map, size_t col_cnt, size_t line_cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < line_cnt)
	{
		if (col_cnt != ft_word_cnt(map[i], ' '))
			map_error();//map 크기 안맞는거 에러
		while (j < col_cnt)
		{
			if (!(('0' <= map[i][j] && map[i][j] <= '9')
				|| map[i][j] == ' ' || map[i][j] == '\n'
				|| map[i][j] == '+' || map[i][j] == '-'))
				map_error();
			j++;
		}
		i++;
	}
}