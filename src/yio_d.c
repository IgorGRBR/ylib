/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yio_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:34:43 by ihhrabar          #+#    #+#             */
/*   Updated: 2024/05/27 20:34:44 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
