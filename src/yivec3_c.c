// TODO: 42 header

#include "yvec3.h"
#include "ytypes.h"

t_ivec3	ivec3_negate(t_ivec3 a)
{
	return ((t_ivec3){.x = -a.x, .y = -a.y, .z = -a.z});
}

t_ivec3	ivec3_dscale(t_ivec3 a, double scalar)
{
	return ((t_ivec3){.x = (int)(a.x * scalar), .y = (int)(a.y * scalar),
		.z = (int)(a.z * scalar)});
}

t_dvec3	ivec3_normalized(t_ivec3 a)
{
	return (dvec3_normalized(dvec3_new((double)a.x, (double) a.y,
		(double) a.z)));
}
