#include "graphics.h"

void	ft_error(int err)
{
	char	*str;

	str = strerror(err);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	args_error(void)
{
	write(2, "invalid number of arguments\n", 28);
	exit(EXIT_FAILURE);
}

void	malloc_failed(void)
{
	write(2, "malloc failed\n", 14);
	exit(EXIT_FAILURE);
}

void	file_error(void)
{
	write(2, "invalid file format\n", 20);
	exit(EXIT_FAILURE);
}

void	map_error(void)
{
	write(2, "wrong map\n", 10);
	exit(EXIT_FAILURE);
}
