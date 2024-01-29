
#include "graphics.h"

void	euler_x(float *old_y, float *old_z, double angle)
{
	float	y;
	float	z;
	float	new_y;
	float	new_z;
	double	radian;

	radian = M_PI / 180.0 * angle;
	y = *old_y;
	z = *old_z;
	new_y = y * cos(radian) - z * sin(radian);
	new_z = y * sin(radian) + z * cos(radian);
	*old_y = new_y;
	*old_z = new_z;
}

void	euler_z(float *old_x, float *old_y, double angle)
{
	float	x;
	float	y;
	float	new_x;
	float	new_y;
	double	radian;

	radian = M_PI / 180.0 * angle;
	x = *old_x;
	y = *old_y;
	new_x = cos(radian) * x - sin(radian) * y;
	new_y = sin(radian) * x + cos(radian) * y;
	*old_x = new_x;
	*old_y = new_y;
}
