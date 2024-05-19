// TODO: 42 header

#include "yvec3.h"
#include "ytypes.h"
#include <math.h>

t_ivec3	ivec3_scale(t_ivec3 a, int scalar)
{
	return ((t_ivec3){.x = a.x * scalar, .y = a.y * scalar,
		.z = a.z * scalar});
}

t_ivec3	ivec3_divide(t_ivec3 a, int scalar)
{
	return ((t_ivec3){.x = a.x / scalar, .y = a.y / scalar,
		.z = a.z / scalar});
}

double	ivec3_length(t_ivec3 a)
{
	return (sqrt(ivec3_length_sq(a)));
}

double	ivec3_length_sq(t_ivec3 a)
{
	return ((double)(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_bool	ivec3_eq(t_ivec3 a, t_ivec3 b)
{
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}
