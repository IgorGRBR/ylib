// TODO: Add 42 School header here

#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

static t_bool	ptr_equal(void *p1, void *p2)
{
	return (p1 == p2);
}

t_map	*map_new(t_hash_func hfunc, t_equals_func efunc)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof (t_map));
	if (map_init(map, hfunc, efunc))
		return (map);
	else
		return (YNULL);
}

t_bool	map_init(t_map *map, t_hash_func hfunc, t_equals_func efunc)
{
	if (!map || !hfunc)
		return (FALSE);
	map->hash_func = hfunc;
	map->equals_func = efunc;
	if (!efunc)
		map->equals_func = ptr_equal;
	return (TRUE);
}

void	map_delete(t_map *map)
{
	map_deinit(map);
	free(map);
}

//TODO
void	map_deinit(t_map *map)
{
	(void)map;
}
