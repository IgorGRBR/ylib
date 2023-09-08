/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:06 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:08 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

void	_map_set_by_hash(t_map *map, t_uint hash, void *key, void *item)
{
	struct s_map_bucket			*bucket;
	struct s_map_item_container	*container;

	bucket = &map->bucket_array[hash % map->bucket_array_size];
	container = _map_item_container_find_item_by_hash(bucket, hash, key,
			map->equals_func);
	if (container || bucket->is_list || !bucket->container.key)
	{
		if (container)
			*container = (struct s_map_item_container){hash, key, item};
		else if (bucket->is_list)
			list_insert(&bucket->items, _map_item_container_new(hash, key,
					item));
		else if (!bucket->container.key)
			bucket->container = (struct s_map_item_container){.hash = hash,
				.key = key, .item = item};
		return ;
	}
	bucket->is_list = TRUE;
	list_insert(&bucket->items, _map_item_container_new(bucket->container.hash,
			bucket->container.key, bucket->container.item));
	bucket->container = (struct s_map_item_container){0, YNULL, YNULL};
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
	if (container && container != &bucket->container)
	{
		list_remove(&bucket->items, container);
		_map_item_container_delete(container);
		if (bucket->items.size == 1)
		{
			container = list_get(&bucket->items, 0);
			bucket->container.hash = container->hash;
			bucket->container.key = container->key;
			bucket->container.item = container->item;
			_map_item_container_delete(container);
			(list_remove_at(&bucket->items, 0), bucket->is_list = FALSE);
		}
	}
}
