/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycstr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:11:30 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:11:31 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YCSTR_H
# define YCSTR_H

# include <stdarg.h>
# include "ytypes.h"

// Return the length of cstring
unsigned int	cstr_len(const char *s);

// Concatenate string src into dst buffer withy the size of dsize (equivalent
// of strlcat)
unsigned int	cstr_lcat(char *dst, const char *src, unsigned int dsize);

// Join 2 cstrings by creating a new one
char			*cstr_join(char const *s1, char const *s2);

// Duplicate a cstring
char			*cstr_dup(const char *s1);

// Convert integer into a cstring
char			*cstr_itoa(int n);

// Convert cstring into a integer
int				cstr_atoi(const char *str);

// Compare 2 strings
int				cstr_cmp(const char *s1, const char *s2);

// Compare up to n characters between 2 strings (equivalent of strncmp)
int				cstr_ncmp(const char *s1, const char *s2, unsigned int n);

// Create a new string that is equivalent to s1 with characters from set
// being trimmed from the beginning and the end
char			*cstr_trim(char const *s1, char const *set);

// Create a new cstring that is a substring of cstring s, starting at st and
// being len characters long
char			*cstr_sub(char const *s, unsigned int st, unsigned int len);

// Interpolate provided parameters into a template cstring
char			*cstr_format(const char *fmt_cstr, ...);

// Interpolate provided parameter list into a template cstring
char			*cstr_vformat(const char *fmt_cstr, va_list *args);

// Try to convert string into a number. Returns TRUE if conversion is
// successful, and writes the number into i. Otherwise returns FALSE
t_bool			cstr_try_atoi(const char *cstr, int *i);

// Checks if 2 cstrings are equal
t_bool			cstr_equal(const char *cstr1, const char *cstr2);

// Cstring hashing using murmur hash
t_uint			cstr_hash(const char *cstr);

// Private function! Murmur hashing algorithm
t_uint			_murmur3_32(const t_uchar *key, t_uint len, t_uint seed);

#endif
