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
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

// Represents a mutable, null-termintated string
typedef struct s_string
{
	char			*cstr;
	unsigned int	size;
}	t_string;

// 2D vector of integers
typedef struct s_ivec2
{
	int	x;
	int	y;
}	t_ivec2;

// 2D vector of doubles
typedef struct s_dvec2
{
	double	x;
	double	y;
}	t_dvec2;

// 3D vector of integers
typedef struct s_ivec3
{
	int	x;
	int	y;
	int	z;
}	t_ivec3;

// 3D vector of doubles
typedef struct s_dvec3
{
	double	x;
	double	y;
	double	z;
}	t_dvec3;

// Hash function for hash maps and sets
typedef t_uint			(*t_hash_func)(void *);

// Equals function for hash maps and sets
typedef t_bool			(*t_equals_func)(void *, void *);

typedef struct s_kv_pair
{
	void	*key;
	void	*value;
}	t_kv_pair;

// Hash Map item container (is private/not meant to be used outside of yLib)
struct s_map_item_container
{
	t_uint		hash;
	t_kv_pair	item;
};

// Hash Map container
// (bucket_array is array of lists of s_map_item_containers)
typedef struct s_map
{
	t_hash_func			hash_func;
	t_equals_func		equals_func;
	t_list				*bucket_array;
	t_uint				bucket_array_size;
	double				upper_realloc_ratio;
	double				lower_realloc_ratio;
	t_uint				upper_realloc_value;
	t_uint				lower_realloc_value;
	double				scaling_ratio;
	t_uint				size;
}	t_map;

// TODO: Map key-value pair iterator
typedef struct s_map_iter
{
	void		*value;
	void		*key;
	t_uint		bucket;
	t_list_iter	bucket_iter;
	t_map		*map;
}	t_map_iter;

#endif
