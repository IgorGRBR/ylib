// TODO: Insert 42 header here

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

t_bool	map_insert(t_map *map, void *key, void *item)
{

}

void	map_set(t_map *map, void *key, void *item)
{
	t_uint	hash;

	hash = map->hash_func(key);
	
}

void	map_remove(t_map *map, void *key)
{

}

void	map_unset(t_map *map, void *key)
{

}

void	*map_get(t_map *map, void *key)
{

}
