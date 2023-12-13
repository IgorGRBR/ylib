/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:21 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:22 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ytypes.h"
#include "ystring.h"
#include "ycmem.h"
#include "ycstr.h"

t_bool	string_equal(t_string *str, t_string *str2)
{
	return (string_compare(str, str2) == 0);
}

t_bool	string_equal_cstr(t_string *str, const char *cstr)
{
	return (cstr_cmp(str->cstr, cstr) == 0);
}

t_uint	string_hash(t_string *str)
{
	return (_murmur3_32((t_uchar *)str->cstr, str->size, 3985));
}
