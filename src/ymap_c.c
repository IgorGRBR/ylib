// TODO: Insert 42 header here

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

// TODO: set and unset functions by hash have an issue
// 0) Resolve the issue
// 1) Split them
void	_map_set_by_hash(t_map *map, t_uint hash, void *key, void *item)
{
	struct s_map_bucket			*bucket;
	struct s_map_item_container	*container;

	bucket = &map->bucket_array[hash % map->bucket_array_size];
	container = _map_item_container_find_item_by_hash(bucket, hash, key,
			map->equals_func);
	if (container)
	{
		container->key = key;
		container->item = item;
		return ;
	}
	if (!bucket->is_list && !bucket->container.key
		&& !bucket->container.item)
	{
		bucket->container = (struct s_map_item_container) { .hash = hash,
			.key = key, .item = item };
		return ;
	}
	else
	{
		list_insert(&bucket->items, _map_item_container_new(
				bucket->container.hash,
				bucket->container.key,
				bucket->container.item));
		bucket->container = (struct s_map_item_container) { 0, YNULL, YNULL };
	}
	list_insert(&bucket->items, _map_item_container_new(hash, key, item));
}


void	_map_unset_by_hash(t_map *map, t_uint hash, void *key)
{
	struct s_map_bucket			*bucket;
	struct s_map_item_container	*container;

	bucket = &map->bucket_array[hash % map->bucket_array_size];
	container = _map_item_container_find_item_by_hash(bucket,
		hash, key, map->equals_func);
	(void)((container) && (container->hash = 0, container->key = YNULL,
		container->item = YNULL));
	if (container != &bucket->container)
	{
		list_remove(&bucket->items, container);
		if (bucket->items.size == 1)
		{
			container = list_get(&bucket->items, 0);
			bucket->container.hash = container->hash;
			bucket->container.key = container->key;
			bucket->container.item = container->item;
			(list_remove_at(&bucket->items, 0), bucket->is_list = FALSE);
		}
	}
}

