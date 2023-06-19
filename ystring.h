/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:54:48 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:54:50 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSTRING_H
# define YSTRING_H
# include "ytypes.h"

t_string	*string_new(void);
t_string	*string_from_cstr(const char *cstr);
t_string	*string_from_char_list(t_list *clist);
t_string	*string_copy(t_string *str);
void		string_delete(t_string *str);
char		string_get(t_string *str, unsigned int i);
void		string_set(t_string *str, unsigned int i, char c);
t_list		*string_to_char_list(t_string *str);
void		string_resize(t_string *str, unsigned int new_size);
char		*string_find_char(t_string *str, char c);
char		*string_find_last_char(t_string *str, char c);
int			string_compare(t_string *str1, t_string *str2);
char		*string_find(t_string *str, t_string *sub);
t_string	*string_concat(t_string *str, t_string *str2);
void		string_append(t_string *str, t_string *str2);
t_string	*string_trim(t_string *str, t_string *set);
char		*string_find_cstr(t_string *str, const char *cstr);
t_string	*string_concat_cstr(t_string *str, char const *cstr);
void		string_append_cstr(t_string *str, char const *cstr);
t_string	*string_trim_cstr(t_string *str, char const *set);
t_list		*string_split(t_string *str, char c);
t_string	*string_map(t_string *str, char (*f)(char, unsigned int));
void		string_apply(t_string *str, void (*f)(char, unsigned int));
t_string	*string_filter(t_string *str, t_bool (*f)(char, unsigned int));
t_string	*string_reverse(t_string *str);
t_string	*string_substring(t_string *str, unsigned int s, unsigned int e);
void		string_delete_as_element(void *str, t_uint i);
void		string_append2(t_string *str2, t_string *str);

#endif
