/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:34:43 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/14 14:34:44 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ymap.h"
#include "ytypes.h"
#include "ymath.h"
#include "ylist.h"
#include "ydefines.h"

void	_map_try_grow(t_map *map)
{
	t_uint	new_size;

	if (map->size > map->upper_realloc_value)
	{
		new_size = get_next_prime(map->bucket_array_size * map->scaling_ratio);
		_map_realloc(map, new_size);
	}
}

void	_map_try_shrink(t_map *map)
{
	t_uint	new_size;

	if (map->size < map->lower_realloc_value
		&& map->bucket_array_size > MAP_INITIAL_SIZE)
	{
		new_size = get_next_prime(map->bucket_array_size / map->scaling_ratio);
		_map_realloc(map, new_size);
	}
}

void	map_apply(t_map *map, t_apply_mfn f)
{
	t_map_iter	it;

	it = map_iter(map);
	while (map_iter_next(&it))
		f(it.key, it.value);
}

t_map	*map_map(t_map *map, t_map_mfn f)
{
	t_map		*result;
	t_map_iter	it;
	t_kv_pair	pair;

	result = map_new(map->hash_func, map->equals_func);
	map_set_realloc_threshold(result, map->upper_realloc_ratio,
		map->lower_realloc_ratio, map->scaling_ratio);
	it = map_iter(map);
	while (map_iter_next(&it))
	{
		pair = f(it.key, it.value);
		map_set(result, pair.key, pair.value);
	}
	return (result);
}

void	map_filter(t_map *map, t_filter_mfn f)
{
	t_map_iter	it;

	it = map_iter(map);
	while (map_iter_next(&it))
	{
		if (!f(it.key, it.value))
			map_unset(map, it.key);
	}
}
