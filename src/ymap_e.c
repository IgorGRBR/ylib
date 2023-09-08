/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:22:58 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 14:23:00 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

t_bool	map_has(t_map *map, void *key)
{
	t_uint				hash;
	struct s_map_bucket	*bucket;

	hash = map->hash_func(key);
	bucket = &map->bucket_array[hash % map->bucket_array_size];
	if (_map_item_container_find_item_by_hash(bucket, hash, key,
			map->equals_func))
		return (TRUE);
	return (FALSE);
}

//TODO
void	map_set_realloc_threshold(t_map *map,
			double threshold_percent,
			double scaling_percent)
{
	(void)map;
	(void)threshold_percent;
	(void)scaling_percent;
}
