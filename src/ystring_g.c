#include "ydefines.h"
#include "ystring.h"
#include "ycstr.h"
#include "ytypes.h"
#include <stdarg.h>
#include <stdlib.h>

t_string	*string_format(t_string *fmt_str, ...)
{
	va_list		argp;
	t_string	*str;

	va_start(argp, fmt_str);
	str = string_vformat(fmt_str, &argp);
	va_end(argp);
	return (str);
}

t_string	*string_vformat(t_string *fmt_str, va_list *args)
{
	char		*formatted;
	t_string	*str;

	formatted = cstr_vformat(fmt_str->cstr, args);
	str = string_from_cstr(formatted);
	free(formatted);
	return (str);
}

t_bool	string_init(t_string *str)
{
	str->cstr = (char *)malloc(sizeof (char));
	str->cstr[0] = '\0';
	str->size = 0;
	return (TRUE);
}

void	string_deinit(t_string *str)
{
	str->size = 0;
	if (str->cstr)
		free(str->cstr);
	str->cstr = YNULL;
}

// TODO: Add 42 School header

#include "ytypes.h"
#include "ystring.h"
#include "ycmem.h"

t_bool	string_equal(t_string *str, t_string *str2)
{
	return (string_compare(str, str2) == 0);
}

static t_uint murmur_32_scramble(t_uint k)
{
	k *= 0xcc9e2d51;
	k = (k << 15) | (k >> 17);
	k *= 0x1b873593;
	return (k);
}

// TODO: Make this thing shorter
static t_uint murmur3_32(const t_uchar* key, t_uint len, t_uint seed)
{
	t_uint	h;
    t_uint	k;
	t_uint	i;

	h = seed;
	i = len >> 2;
    while (i)
	{
        ymem_copy(&k, key, sizeof(t_uint));
        key += sizeof(t_uint);
        h ^= murmur_32_scramble(k);
        h = (h << 13) | (h >> 19);
        h = h * 5 + 0xe6546b64;
		i--;
    }
    k = 0;
	i = len & 3;
    while (i)
	{
        k <<= 8;
        k |= key[i - 1];
		i--;
    }
    h ^= murmur_32_scramble(k);
	h ^= len;
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;
	return (h);
}

t_uint	string_hash(t_string *str)
{
	return (murmur3_32((t_uchar *)str->cstr, str->size, 3985));
}