// TODO: insert 42 header here

#include "yio.h"
#include "ystring.h"
#include "ydefines.h"
#include <stdlib.h>

t_string	*read_file_to_string(int fd)
{
	t_string	*str;
	char		*line;

	line = get_next_line(fd);
	if (!line)
		return (YNULL);
	str = string_from_cstr(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		string_append_cstr(str, line);
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}
