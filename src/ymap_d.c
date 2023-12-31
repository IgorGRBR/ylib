/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:15 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:16 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

t_bool	map_insert(t_map *map, void *key, void *value)
{
	t_uint	hash;
	t_list	*bucket;
	t__mic	*container;

	if (!key || !map)
		return (FALSE);
	hash = map->hash_func(key);
	bucket = &map->bucket_array[hash % map->bucket_array_size];
	container = _map_item_container_find_item_by_hash(bucket, hash, key,
			map->equals_func);
	if (container)
		return (FALSE);
	_map_set_by_hash(map, hash, (t_kv_pair){key, value});
	return (TRUE);
}

void	map_set(t_map *map, void *key, void *value)
{
	if (!key || !map)
		return ;
	_map_set_by_hash(map, map->hash_func(key), (t_kv_pair){key, value});
}

t_bool	map_remove(t_map *map, void *key)
{
	t_uint	hash;
	t_list	*bucket;
	t__mic	*container;

	if (!key || !map)
		return (FALSE);
	hash = map->hash_func(key);
	bucket = &map->bucket_array[hash % map->bucket_array_size];
	container = _map_item_container_find_item_by_hash(bucket, hash, key,
			map->equals_func);
	if (!container)
		return (FALSE);
	_map_unset_by_hash(map, hash, key);
	return (TRUE);
}

void	map_unset(t_map *map, void *key)
{
	if (!key || !map)
		return ;
	_map_unset_by_hash(map, map->hash_func(key), key);
}

void	*map_get(t_map *map, void *key)
{
	t_uint	hash;
	t_list	*bucket;
	t__mic	*container;

	if (!key || !map)
		return (YNULL);
	hash = map->hash_func(key);
	bucket = &map->bucket_array[hash % map->bucket_array_size];
	container = _map_item_container_find_item_by_hash(bucket, hash, key,
			map->equals_func);
	if (container)
		return (container->item.value);
	return (NULL);
}
