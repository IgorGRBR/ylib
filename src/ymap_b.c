/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:02 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:04 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

static void	init_bucket_array(t_list *array, t_uint size)
{
	t_uint	i;

	i = 0;
	while (i < size)
	{
		list_init(&array[i]);
		i++;
	}
}

static void	set_item(struct s_map_item_container *container, t_map *new_map)
{
	_map_set_by_hash(new_map, container->hash, container->item);
}

static void	redistribute_items(t_map *map, t_list *old_array, t_uint old_size)
{
	t_uint	i;

	i = 0;
	while (i < old_size)
	{
		list_capply(&old_array[i], (t_capply_lfn) set_item,
			map);
		list_apply(&old_array[i],
			(t_apply_lfn)_map_item_container_delete);
		list_deinit(&old_array[i]);
		i++;
	}
}

void	_map_realloc(t_map *map, t_uint new_size)
{
	t_list	*old_array;
	t_uint	old_size;

	if (!map || new_size == 0)
		return ;
	old_array = map->bucket_array;
	map->bucket_array = malloc(sizeof (t_list) * new_size);
	init_bucket_array(map->bucket_array, new_size);
	map->upper_realloc_value = map->upper_realloc_ratio * new_size;
	map->lower_realloc_value = map->lower_realloc_ratio * new_size;
	old_size = map->bucket_array_size;
	map->bucket_array_size = new_size;
	if (old_array)
	{
		map->bucket_array_size = new_size;
		redistribute_items(map, old_array, old_size);
		free(old_array);
	}
}

t_map	*map_copy(t_map *map)
{
	t_map	*copy;
	t_uint	i;

	if (!map)
		return (YNULL);
	copy = map_new(map->hash_func, map->equals_func);
	map_set_realloc_threshold(copy, map->upper_realloc_ratio,
		map->lower_realloc_ratio, map->scaling_ratio);
	_map_realloc(copy, map->bucket_array_size);
	copy->size = map->size;
	i = 0;
	while (i < copy->bucket_array_size)
	{
		list_init_from_list(&copy->bucket_array[i],
			&map->bucket_array[i]);
		i++;
	}
	return (copy);
}
