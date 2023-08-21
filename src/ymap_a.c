// TODO: Add 42 School header here

#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"

static t_bool	ptr_equal(void *p1, void *p2)
{
	return (p1 == p2);
}

t_map	*new_map(t_hash_func hfunc, t_equals_func efunc)
{
	(void)hfunc;
	(void)efunc;
	(void)ptr_equal;
	return (YNULL);
}