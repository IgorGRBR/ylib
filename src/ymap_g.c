/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:37 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/10/24 13:30:39 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ymap.h"
#include "ytypes.h"
#include "ylist.h"
#include "ydefines.h"

t_map	*map_filter_new(t_map *map, t_filter_mfn f)
{
	t_map_iter	it;
	t_map		*result;

	result = map_new(map->hash_func, map->equals_func);
	map_set_realloc_threshold(result, map->upper_realloc_ratio,
		map->lower_realloc_ratio, map->scaling_ratio);
	it = map_iter(map);
	while (map_iter_next(&it))
	{
		if (f(it.key, it.value))
			map_set(result, it.key, it.value);
	}
	return (result);
}

void	map_capply(t_map *map, t_capply_mfn f, void *context)
{
	t_map_iter	it;

	it = map_iter(map);
	while (map_iter_next(&it))
		f(it.key, it.value, context);
}

t_map	*map_cmap(t_map *map, t_cmap_mfn f, void *context)
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
		pair = f(it.key, it.value, context);
		map_set(result, pair.key, pair.value);
	}
	return (result);
}

void	map_cfilter(t_map *map, t_cfilter_mfn f, void *context)
{
	t_map_iter	it;

	it = map_iter(map);
	while (map_iter_next(&it))
	{
		if (!f(it.key, it.value, context))
			map_unset(map, it.key);
	}
}

t_map	*map_cfilter_new(t_map *map, t_cfilter_mfn f, void *context)
{
	t_map_iter	it;
	t_map		*result;

	result = map_new(map->hash_func, map->equals_func);
	map_set_realloc_threshold(result, map->upper_realloc_ratio,
		map->lower_realloc_ratio, map->scaling_ratio);
	it = map_iter(map);
	while (map_iter_next(&it))
	{
		if (f(it.key, it.value, context))
			map_set(result, it.key, it.value);
	}
	return (result);
}
