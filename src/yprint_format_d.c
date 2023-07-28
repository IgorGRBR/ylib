#include "yprint_format.h"
#include "ycstr.h"

char	*format_none(va_list *args, t_pconvdata cdata)
{
	(void)args;
	(void)cdata;
	return (cstr_dup(""));
}