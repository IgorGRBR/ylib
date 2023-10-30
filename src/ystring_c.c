/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:56:06 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:56:06 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"
#include "ylist.h"
#include "ycstr.h"
#include "ydefines.h"

int	string_find_last_char(t_string *str, char c)
{
	int	i;

	i = str->size;
	while (i > 0)
	{
		i--;
		if (str->cstr[i] == c)
			return (i);
	}
	return (-1);
}

int	string_compare(t_string *str1, t_string *str2)
{
	unsigned int	i;
	unsigned int	max;

	i = 0;
	max = (str1->size >= str2->size) * str1->size;
	max += (str1->size < str2->size) * str2->size;
	while (i < max)
	{
		if (i >= str2->size)
			return (str1->cstr[i]);
		else if (i >= str1->size)
			return (-str2->cstr[i]);
		if (str1->cstr[i] != str2->cstr[i])
			return (str1->cstr[i] - str2->cstr[i]);
		i++;
	}
	return (0);
}

int	string_find_cstr(t_string *str, const char *cstr)
{
	int	i;
	int	clen;
	int	s;

	i = 0;
	clen = cstr_len(cstr);
	if (clen > (int)str->size || clen == 0)
		return (-1);
	s = 0;
	while (i - s <= (int)str->size - clen)
	{
		if (str->cstr[i] != cstr[s])
			s = 0;
		else
			s++;
		if (s == clen)
			return ((i - s + 1));
		i++;
	}
	return (-1);
}

t_string	*string_concat_cstr(t_string *str, char const *cstr)
{
	t_string	*result;

	result = string_copy(str);
	string_append_cstr(result, cstr);
	return (result);
}

void	string_append_cstr(t_string *str, char const *cstr)
{
	unsigned int	i;
	unsigned int	l;
	unsigned int	k;

	l = str->size;
	k = cstr_len(cstr);
	string_resize(str, l + k);
	i = 0;
	while (i < k)
	{
		str->cstr[i + l] = cstr[i];
		i++;
	}
	str->cstr[i + l] = '\0';
}
