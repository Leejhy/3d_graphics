
#include "graphics.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	xyz_frees(t_xyz **xyz, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(xyz[i]);
		i++;
	}
	free(xyz);
}
