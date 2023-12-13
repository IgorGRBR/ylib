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
# include <stdarg.h>

// Create and initialize a new empty string
t_string	*string_new(void);

// Initialize a new empty string
t_bool		string_init(t_string *str);

// Create a new string from cstring
t_string	*string_from_cstr(const char *cstr);

// Initialize a new string from cstring
t_bool		string_init_from_cstr(t_string *str, const char *cstr);

// Create a string from the list of characters
t_string	*string_from_char_list(t_list *clist);

// Initialize a new string from the list of characters
t_bool		string_init_from_char_list(t_string *str, t_list *clist);

// Copy a string
t_string	*string_copy(const t_string *str);

// Initialize a new string as a copy of other string
t_bool		string_copy_from_string(t_string *str, const t_string *str2);

// Deinitialize and delete a string
void		string_delete(t_string *str);

// Deinitialize a string
void		string_deinit(t_string *str);

// Return character of string str at i. Returns '\0' if i is out of bounds
char		string_get(t_string *str, unsigned int i);

// Set the character of string str at i to c with a bounds check
void		string_set(t_string *str, unsigned int i, char c);

// Create a list of character pointers of characters from string str. Each
// character is malloced, so freeing is necessary after use
t_list		*string_to_char_list(t_string *str);

// Resize the string buffer to the new_size by reallocating the cstring buffer.
// Fills out the rest of the buffer with '\0', if new_size is larger than the
// string size
void		string_resize(t_string *str, unsigned int new_size);

// Finds the index of first occurence of character c in string str. Returns
// -1 if c wasn't found
int			string_find_char(t_string *str, char c);

// Finds the index of first occurence of character c in string str, starting
// from i. Returns -1 if c wasn't found
int			string_find_char_next(t_string *str, char c, t_uint i);

// Same as string_find_char, except this function finds the last occurence of
// character c in string str
int			string_find_last_char(t_string *str, char c);

// Compare 2 strings. Returns the difference of first 2 non-matching characters
// or 0 if all characters are match
int			string_compare(t_string *str1, t_string *str2);

// Returns the index of the beginning of a substring within a string, or -1 if
// string does not contain the substring
int			string_find(t_string *str, t_string *sub);

// Creates a new string by concatenating 2 strings
t_string	*string_concat(t_string *str, t_string *str2);

// Appends a string to an existing string by reallocating the string buffer
// and writing the other string into it
void		string_append(t_string *str, t_string *str2);

// Creates a new string that is equivalent to the old string with the
// characters from set being trimmed from it
t_string	*string_trim(t_string *str, t_string *set);

// Same as string_find, except this function looks for cstring within a
// string
int			string_find_cstr(t_string *str, const char *cstr);

// Same as string_concat, except it concatenates the cstring instead of
// a string
t_string	*string_concat_cstr(t_string *str, char const *cstr);

// Same as string_append, except it appends the cstring instead of a
// string
void		string_append_cstr(t_string *str, char const *cstr);

// Same as string_trim, except the set is specified as a cstring instead
// of a string
t_string	*string_trim_cstr(t_string *str, char const *set);

// Splits the string by character c into a list of strings 
t_list		*string_split(t_string *str, char c);

// Map the characters of a string into a new one
t_string	*string_imap(t_string *str, char (*f)(char, unsigned int));

// Apply a function over all characters of a string
void		string_iapply(t_string *str, void (*f)(char, unsigned int));

// Create a new string by applying filter function to a string
t_string	*string_ifilter_new(t_string *str, t_bool (*f)(char, unsigned int));

// Create a reversed string
t_string	*string_reverse(t_string *str);

// Create a substring from a string, starting at s (inclusive) and ending at
// e (exclusive)
t_string	*string_substring(t_string *str, unsigned int s, unsigned int e);

// Helper function to delete a string from within list_iapply (Deprecated)
void		string_delete_as_element(void *str, t_uint i);

// Same as string_append, except the string in the first argument gets appended
// to the one in the second argument
void		string_append2(t_string *str2, t_string *str);

// String equality check
t_bool		string_equal(t_string *str, t_string *str2);

// String equality check
t_bool		string_equal_cstr(t_string *str, const char *cstr);

// String hashing using murmur hash
t_uint		string_hash(t_string *str);

// Interpolate provided parameters into a template string
t_string	*string_format(t_string *fmt_str, ...);

// Interpolate provided parameter list into a template string
t_string	*string_vformat(t_string *fmt_str, va_list *args);

// Interpolate provided parameters into a template cstring
t_string	*string_format_cstr(char *fmt_cstr, ...);

// Interpolate provided parameter list into a template cstring
t_string	*string_vformat_cstr(char *fmt_cstr, va_list *args);

// Join list of strings into a single string with specified delimeter string
t_string	*string_join(t_list *strings, t_string *delim);

// Join list of strings into a single string with specified delimeter cstring
t_string	*string_join_cstr(t_list *strings, char *delim);

#endif
