// TODO: 42 header

#include "ytypes.h"
#include "yvec2.h"

t_ivec2	ivec2_mul(t_ivec2 a, t_ivec2 b)
{
	return ((t_ivec2){.x = a.x * b.x, .y = a.y * b.y});
}

t_ivec2	ivec2_div(t_ivec2 a, t_ivec2 b)
{
	return ((t_ivec2){.x = a.x / b.x, .y = a.y / b.y});
}
