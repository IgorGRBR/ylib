/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:07:33 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:07:34 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"
#include "ylist.h"
// #include "ychar.h"
#include "ycstr.h"
#include <stdlib.h>
#include "ydefines.h"

t_string	*string_new(void)
{
	t_string	*str;

	str = (t_string *)malloc(sizeof (t_string));
	str->cstr = (char *)malloc(sizeof (char));
	str->cstr[0] = '\0';
	str->size = 0;
	return (str);
}

t_string	*string_from_cstr(const char *cstr)
{
	t_string		*str;
	unsigned int	i;

	str = (t_string *)malloc(sizeof (t_string));
	str->size = cstr_len(cstr);
	i = 0;
	str->cstr = (char *)malloc(sizeof (char) * (str->size + 1));
	while (cstr[i])
	{
		str->cstr[i] = cstr[i];
		i++;
	}
	str->cstr[i] = '\0';
	return (str);
}

t_string	*string_from_char_list(t_list *clist)
{
	t_string		*str;
	unsigned int	i;

	str = (t_string *)malloc(sizeof (t_string));
	str->size = clist->size;
	i = 0;
	str->cstr = (char *)malloc(sizeof (char) * (str->size + 1));
	while (i < clist->size)
	{
		str->cstr[i] = *(char *)list_get(clist, i);
		i++;
	}
	str->cstr[i] = '\0';
	return (str);
}

t_string	*string_copy(t_string *str)
{
	t_string		*copy;
	unsigned int	i;

	copy = (t_string *)malloc(sizeof (t_string));
	copy->size = str->size;
	copy->cstr = (char *)malloc(sizeof (char) * (copy->size + 1));
	i = 0;
	while (i < str->size)
	{
		copy->cstr[i] = str->cstr[i];
		i++;
	}
	copy->cstr[i] = '\0';
	return (copy);
}

void	string_delete(t_string *str)
{
	if (str->cstr)
		free(str->cstr);
	free(str);
}
