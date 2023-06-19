/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ytypes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:27 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 11:38:28 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YTYPES_H
# define YTYPES_H

// Because "unsigned int" is too long
typedef unsigned int	t_uint;
typedef long int		t_uint_ptr;
typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;

// A structure representing the list of pointers to the data.
// s_list does not own the values themselves
typedef struct s_list
{
	unsigned int	size;
	unsigned int	capacity;
	void			**data;
}	t_list;

// List iterator
typedef struct s_list_iter
{
	void			*value;
	unsigned int	i;
	t_list			*list;
}	t_list_iter;

// Represents a boolean value
typedef enum e_bool {
	FALSE,
	TRUE
}	t_bool;

// Represents a mutable, null-termintated string
typedef struct s_string {
	char			*cstr;
	unsigned int	size;
}	t_string;

// Represents a safe result wrapper (not typesafe tho lmao)
// typedef struct s_result {
// 	void			*value;
// 	t_bool			status;
// 	t_bool			verified;
// }	t_result;

typedef struct s_ivec2 {
	int	x;
	int	y;
}	t_ivec2;

typedef struct s_dvec2 {
	double	x;
	double	y;
}	t_dvec2;

#endif
