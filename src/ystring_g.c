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
