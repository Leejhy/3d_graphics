#include <stdio.h>
#include <math.h>

void	Euler_x(float *old_y, float *old_z, double angle)
{
	float	y;
	float	z;
	float	new_y;
	float	new_z;

	y = *old_y;
	z = *old_z;
	new_y = y * cos(angle) - z * sin(angle);
	new_z = y * sin(angle) + z * cos(angle);
	*old_y = new_y;
	*old_z = new_z;
}

void	Euler_y(float *old_x, float *old_z, double angle)
{
	float	x;
	float	z;
	float	new_x;
	float	new_z;

	x = *old_x;
	z = *old_z;
	new_x = cos(angle) * x - sin(angle) * z;
	new_z = sin(angle) * x + cos(angle) * z;
	*old_x = x;
	*old_z = z;
}

void	Euler_z(float *old_x, float *old_y, double angle)
{
	float	x;
	float	y;
	float	new_x;
	float	new_y;

	x = *old_x;
	y = *old_y;
	new_x = cos(angle) * x - sin(angle) * y;
	new_y = sin(angle) * x + cos(angle) * y;
}

int	main(int argc, char **argv)
{
	
}
