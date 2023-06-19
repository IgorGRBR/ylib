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

unsigned int	cstr_len(const char *s);
unsigned int	cstr_lcat(char *dst, const char *src, unsigned int dsize);
char			*cstr_join(char const *s1, char const *s2);
char			*cstr_dup(const char *s1);
char			*cstr_itoa(int n);
int				cstr_atoi(const char *str);
int				cstr_ncmp(const char *s1, const char *s2, unsigned int n);
char			*cstr_trim(char const *s1, char const *set);
char			*cstr_sub(char const *s, unsigned int st, unsigned int len);

#endif
