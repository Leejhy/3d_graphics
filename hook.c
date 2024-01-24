
#include "fdf.h"

int	esc_hook(int key, t_vars *vars)
{
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}