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

static void	insert_container(t_map *map, t_list *bucket,
		struct s_map_item_container *container)
{
	if (bucket)
		list_insert(bucket, container);
	map->size++;
	_map_try_grow(map);
}

void	_map_set_by_hash(t_map *map, t_uint hash, t_kv_pair item)
{
	t_list	*bucket;
	t__mic	*container;

	bucket = &map->bucket_array[hash % map->bucket_array_size];
	container = _map_item_container_find_item_by_hash(bucket, hash,
			item.key, map->equals_func);
	if (container)
	{
		*container = (t__mic){hash, item};
	}
	else
	{
		container = _map_item_container_new(hash, item);
		insert_container(map, bucket, container);
	}
}

void	_map_unset_by_hash(t_map *map, t_uint hash, void *key)
{
	t_list	*bucket;
	t__mic	*container;

	bucket = &map->bucket_array[hash % map->bucket_array_size];
	container = _map_item_container_find_item_by_hash(bucket, hash,
			key, map->equals_func);
	if (container)
	{
		*container = (t__mic){0, {YNULL, YNULL}};
		list_remove(bucket, container);
		_map_item_container_delete(container);
		map->size--;
		_map_try_shrink(map);
	}
}

void	map_delete(t_map *map)
{
	map_deinit(map);
	free(map);
}
