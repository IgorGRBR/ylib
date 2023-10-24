/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:35 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:36 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ydefines.h"
#include <stdlib.h>

t_bool	list_init(t_list *list)
{
	list->size = 0;
	list->capacity = 0;
	list->data = YNULL;
	return (TRUE);
}

void	list_deinit(t_list *list)
{
	list->size = 0;
	list->capacity = 0;
	if (list->data)
		free(list->data);
	list->data = YNULL;
}

t_bool		list_init_from_list(t_list *list, t_list *other)
{
	t_uint	i;

	list->size = other->size;
	list->capacity = other->capacity;
	list->data = (void **)malloc(sizeof (void *) * list->capacity);
	i = 0;
	while (i < list->size)
	{
		list->data[i] = other->data[i];
		i++;
	}
	return (TRUE);
}