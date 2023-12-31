/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_container_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:11 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:12 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

struct s_map_item_container	*
	_map_item_container_new(t_uint hash, t_kv_pair item)
{
	struct s_map_item_container	*container;

	container = malloc(sizeof (struct s_map_item_container));
	container->hash = hash;
	container->item = item;
	return (container);
}

void	_map_item_container_delete(struct s_map_item_container *container)
{
	free(container);
}

struct s_map_item_container
	*_map_item_container_find_item_by_hash(t_list *bucket,
			t_uint hash, void *key, t_equals_func efunc)
{
	t_list_iter					it;
	struct s_map_item_container	*container;

	if (!bucket)
		return (YNULL);
	it = list_iter(bucket);
	while (list_iter_next(&it))
	{
		container = it.value;
		if (container->hash == hash && efunc(container->item.key, key))
			return (container);
	}
	return (YNULL);
}
