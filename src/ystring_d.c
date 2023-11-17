/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:07:46 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:07:47 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"
#include "ylist.h"
#include "ycstr.h"
#include "ydefines.h"
#include "ytypes.h"

static int	char_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

t_string	*string_trim_cstr(t_string *str, char const *set)
{
	unsigned int	i;
	unsigned int	c;

	if (!str || !str->cstr)
		return (YNULL);
	if (!set || str->size == 0)
		return (string_copy(str));
	i = 0;
	while (char_in_set(string_get(str, i), set))
		i++;
	c = i;
	i = str->size - 1;
	while (char_in_set(string_get(str, i), set) && i > c)
		i--;
	return (string_substring(str, c, i + 1));
}

t_string	*string_imap(t_string *str, char (*f)(char, unsigned int))
{
	t_string	*result;
	t_uint		i;

	result = string_new();
	string_resize(result, str->size);
	i = 0;
	while (i < str->size)
	{
		result->cstr[i] = f(str->cstr[i], i);
		i++;
	}
	return (result);
}

void	string_iapply(t_string *str, void (*f)(char, unsigned int))
{
	t_uint	i;

	i = 0;
	while (i < str->size)
	{
		f(str->cstr[i], i);
		i++;
	}
}

t_string	*string_ifilter_new(t_string *str, t_bool (*f)(char, unsigned int))
{
	t_string	*result;
	t_uint		i;
	t_uint		j;

	result = string_new();
	string_resize(result, str->size);
	i = 0;
	j = 0;
	while (i < str->size)
	{
		if (f(str->cstr[i], i))
		{
			result->cstr[j] = str->cstr[i];
			j++;
		}
		i++;
	}
	string_resize(result, j);
	return (result);
}
