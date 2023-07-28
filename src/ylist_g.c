#include "ylist.h"
#include "ydefines.h"
#include <stdlib.h>

t_bool		list_init(t_list *list)
{
	list->size = 0;
	list->capacity = 0;
	list->data = YNULL;
	return (TRUE);
}

void		list_deinit(t_list *list)
{
	list->size = 0;
	list->capacity = 0;
	if (list->data)
		free(list->data);
	list->data = YNULL;
}