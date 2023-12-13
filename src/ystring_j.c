/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_j.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:26:30 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/11/13 15:26:31 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ytypes.h"
#include "ystring.h"
#include "ycstr.h"
#include "ydefines.h"
#include <stdlib.h>

// Interpolate provided parameters into a template cstring
t_string	*string_format_cstr(char *fmt_cstr, ...)
{
	va_list		argp;
	t_string	*str;

	va_start(argp, fmt_cstr);
	str = string_vformat_cstr(fmt_cstr, &argp);
	va_end(argp);
	return (str);
}

// Interpolate provided parameter list into a template cstring
t_string	*string_vformat_cstr(char *fmt_cstr, va_list *args)
{
	char		*formatted;
	t_string	*str;

	formatted = cstr_vformat(fmt_cstr, args);
	str = string_from_cstr(formatted);
	free(formatted);
	return (str);
}

int	string_find_char_next(t_string *str, char c, t_uint i)
{
	while (i < str->size)
	{
		if (str->cstr[i] == c)
			return ((int)i);
		i++;
	}
	return (-1);
}
