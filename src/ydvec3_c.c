// TODO: 42 header

#include "ytypes.h"
#include "yvec3.h"

t_dvec3	dvec3_normalized(t_dvec3 a)
{
	return (dvec3_divide(a, dvec3_length(a)));
}

t_dvec3	dvec3_mul(t_dvec3 a, t_dvec3 b)
{
	return (t_dvec3){.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z};
}

t_dvec3	dvec3_div(t_dvec3 a, t_dvec3 b)
{
	return (t_dvec3){.x = a.x / b.x, .y = a.y / b.y, .z = a.z / b.z};
}

t_dvec3	dvec3_cross(t_dvec3 a, t_dvec3 b)
{
	return (t_dvec3){.x = a.y * b.z - a.z * b.y,
		.y = a.z * b.x - a.x * b.z,
		.z = a.x * b.y - a.y * b.x};
}
