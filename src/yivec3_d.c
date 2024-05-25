// TODO: 42 header

#include "yvec3.h"
#include "ytypes.h"

t_ivec3	ivec3_mul(t_ivec3 a, t_ivec3 b)
{
	return ((t_ivec3){.x = a.x * b.x, .y = a.y * b.y, .z = a.z * b.z});
}

t_ivec3	ivec3_div(t_ivec3 a, t_ivec3 b)
{
	return ((t_ivec3){.x = a.x / b.x, .y = a.y / b.y, .z = a.z / b.z});
}

t_ivec2	ivec3_xy(t_ivec3 a)
{
	return ((t_ivec2){.x = a.x, .y = a.y});
}

t_ivec2	ivec3_xz(t_ivec3 a)
{
	return ((t_ivec2){.x = a.x, .y = a.z});
}

t_ivec2	ivec3_yz(t_ivec3 a)
{
	return ((t_ivec2){.x = a.y, .y = a.z});
}