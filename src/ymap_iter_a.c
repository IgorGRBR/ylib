/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_iter_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:40:55 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/10/24 13:40:56 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ymap.h"
#include "ytypes.h"
#include "ylist.h"
#include "ydefines.h"

t_map_iter	map_iter(t_map *map)
{
	t_map_iter	it;

	it.bucket = 0;
	it.key = YNULL;
	it.value = YNULL;
	it.map = map;
	it.bucket_iter = list_iter(YNULL);
	return (it);
}

static t__mic	*get_next_container(t_map *map, t_uint *bucket, t_list_iter *it)
{
	t_list	*bucket_ptr;

	if (it->list && list_iter_next(it))
		return (it->value);
	if (*bucket >= map->bucket_array_size)
		return (YNULL);
	bucket_ptr = &map->bucket_array[*bucket];
	while (*bucket < map->bucket_array_size)
	{
		*it = list_iter(bucket_ptr);
		(void)(*bucket)++;
		if (list_iter_next(it))
			return (it->value);
		bucket_ptr = &map->bucket_array[*bucket];
	}
	return (YNULL);
}

t_bool	map_iter_next(t_map_iter *iter)
{
	t__mic	*container;

	if (!iter || !iter->map)
		return (FALSE);
	container = get_next_container(iter->map, &iter->bucket,
			&iter->bucket_iter);
	if (container)
	{
		iter->key = container->item.key;
		iter->value = container->item.value;
		return (TRUE);
	}
	iter->key = YNULL;
	iter->value = YNULL;
	return (FALSE);
}
