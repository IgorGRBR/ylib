// TODO: 42 header

#include "yvec3.h"
#include "ytypes.h"
#include <math.h>

t_dvec3	dvec3_scale(t_dvec3 a, double scalar)
{
	return ((t_dvec3){.x = a.x * scalar, .y = a.y * scalar,
		.z = a.z * scalar});
}

t_dvec3	dvec3_divide(t_dvec3 a, double scalar)
{
	return ((t_dvec3){.x = a.x / scalar, .y = a.y / scalar,
		.z = a.z /scalar});
}

double	dvec3_length(t_dvec3 a)
{
	return (sqrt(dvec3_length_sq(a)));
}

double	dvec3_length_sq(t_dvec3 a)
{
	return ((double)(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_dvec3	dvec3_negate(t_dvec3 a)
{
	return ((t_dvec3){.x = -a.x, .y = -a.y, .z = -a.z});
}
