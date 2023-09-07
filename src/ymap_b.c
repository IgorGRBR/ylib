// TODO: Add 42 School header here

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

static void	init_bucket_array(struct s_map_bucket *array, t_uint size)
{
	t_uint	i;

	i = 0;
	while (i < size)
	{
		array[i] = (struct s_map_bucket) {
			.is_list = FALSE,
			.container = (struct s_map_item_container) {
				.hash = 0,
				.key = YNULL,
				.item = YNULL,
			},
		};
		list_init(&array[i].items);
		i++;
	}
}

static void	set_item(struct s_map_item_container *container, t_map *new_map)
{
	_map_set_by_hash(new_map, container->hash, container->key, 
					container->item);
}

static void	redistribute_items(t_map *map,
			struct s_map_bucket *old_array, t_uint old_size)
{
	t_uint	i;

	i = 0;
	while (i < old_size)
	{
		if (old_array[i].is_list)
			list_apply(&old_array[i].items, (t_apply_func) set_item);
		else if (old_array[i].container.key && old_array[i].container.item)
		{
			_map_set_by_hash(map,
							old_array[i].container.hash,
							old_array[i].container.key,
							old_array[i].container.item);
			list_apply(&old_array[i].items,
					(t_apply_func)_map_item_container_delete);
			list_deinit(&old_array[i].items);
		}
		i++;
	}
}

void	_map_realloc(t_map *map, t_uint new_size)
{
	struct s_map_bucket	*old_array;
	t_uint				old_size;

	if (!map || new_size == 0)
		return ;
	old_array = map->bucket_array;
	map->bucket_array = malloc(sizeof (struct s_map_bucket) * new_size);
	init_bucket_array(map->bucket_array, new_size);
	if (old_array)
	{
		old_size = map->bucket_array_size;
		map->bucket_array_size = new_size;
		redistribute_items(map, old_array, old_size);
		free(old_array);
	}
}
