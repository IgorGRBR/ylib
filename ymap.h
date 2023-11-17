/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:43:14 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:43:15 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YMAP_H
# define YMAP_H
# include "ytypes.h"
# ifndef MAP_INITIAL_SIZE
#  define MAP_INITIAL_SIZE 17
# endif
# ifndef MAP_UPPER_REALLOC_RATIO
#  define MAP_UPPER_REALLOC_RATIO 0.8
# endif
# ifndef MAP_LOWER_REALLOC_RATIO
#  define MAP_LOWER_REALLOC_RATIO 0.3
# endif
# ifndef MAP_SCALING_RATIO
#  define MAP_SCALING_RATIO 1.5
# endif
# define E s_map_item_container

typedef struct E	t__mic;

// Create and initialize a new empty map with specified equals and hashing
// functions. If efunc is NULL, then equality will be checked by comparing
// pointers
t_map				*map_new(t_hash_func hfunc, t_equals_func efunc);

// Initialize a new empty map with specified equals and hashing
// functions. If efunc is NULL, then equality will be checked by comparing
// pointers
t_bool				map_init(t_map *map, t_hash_func hfunc,
						t_equals_func efunc);

// Deinitialize and delete a map
void				map_delete(t_map *map);

// Deinitialize a map
void				map_deinit(t_map *map);

// Private function! Reallocates the space for the map
void				_map_realloc(t_map *map, t_uint new_size);

// Insert item with key into the map if it doesn't exist. Returns FALSE if
// item exists, otherwise returns TRUE
t_bool				map_insert(t_map *map, void *key, void *value);

// Private function! Sets the value of map at the specified key to the
// specified value. Used internally for fast reallocations by skipping
// hashing process.
void				_map_set_by_hash(t_map *map, t_uint hash, t_kv_pair item);

// Private function! Unsets the value of map at the specified key to
// NULL. Used internally for fast reallocations by skipping
// hashing process.
void				_map_unset_by_hash(t_map *map, t_uint hash, void *key);

// Sets the value of the map at specified key to the item
void				map_set(t_map *map, void *key, void *value);

// Sets the value of the map at specified key without updating the value of key
// if it exists
void				map_set_value(t_map *map, void *key, void *value);

// Removes item with specified key from the map if it exist. Returns TRUE
// if item exists, otherwise returns FALSE
t_bool				map_remove(t_map *map, void *key);

// Unsets the value of map at specified key to NULL
void				map_unset(t_map *map, void *key);

// Retrieves item from the map by the specified key
void				*map_get(t_map *map, void *key);

// Retrieves key-value pair from the map by the specified key
t_kv_pair			map_get_pair(t_map *map, void *key);

// Checks if map has the value mapped to the specified key
t_bool				map_has(t_map *map, void *key);

// Utility function to set the required ratio of bucket items/bucket count to
// invoke the reallocation and scaling percentage of the resulting bucket 
// array. Default value for bucket items/bucket count ratio is 0.7 and can be
// changed with MAP_REALLOC_RATIO define/macro. The default value for scaling
// percentage is 1.5, and can be changed with MAP_SCALING_RATIO.
void				map_set_realloc_threshold(t_map *map,
						double upper_realloc_ratio,
						double lower_realloc_ratio,
						double scaling_percent);

// Private function! Allocates and initializes map item container
t__mic				*_map_item_container_new(t_uint hash, t_kv_pair item);

// Private function! Deinitializes and deallocates map item container
void				_map_item_container_delete(t__mic *container);

// Private function! Returns a pointer to the item container
t__mic				*_map_item_container_find_item_by_hash(t_list *bucket,
						t_uint hash, void *key, t_equals_func efunc);

// Private functions! These functions resize map's bucket container size if it
// meets reallocation criteria.
void				_map_try_grow(t_map *map);
void				_map_try_shrink(t_map *map);

// Copy a map
t_map				*map_copy(t_map *map);

// Function types
typedef void		(*t_apply_mfn)(void *, void *);
typedef t_kv_pair	(*t_map_mfn)(void *, void *);
typedef t_bool		(*t_filter_mfn)(void *, void *);
typedef void		(*t_capply_mfn)(void *, void *, void *);
typedef t_kv_pair	(*t_cmap_mfn)(void *, void *, void *);
typedef t_bool		(*t_cfilter_mfn)(void *, void *, void *);

/// Map manipulation functions
// Apply a function to each map element
void				map_apply(t_map *map, t_apply_mfn f);

// Build a new map by applying mapping function to a given map
t_map				*map_map(t_map *map, t_map_mfn f);

// Filter a map with given function
void				map_filter(t_map *map, t_filter_mfn f);

// Build a new, filtered map
t_map				*map_filter_new(t_map *map, t_filter_mfn f);

// Apply a function to each map element with given context
void				map_capply(t_map *map, t_capply_mfn f, void *context);

// Build a new map by applying mapping function to a given map with given
// context
t_map				*map_cmap(t_map *map, t_cmap_mfn f, void *context);

// Filter a map with given function with given context
void				map_cfilter(t_map *map, t_cfilter_mfn f, void *context);

// Build a new, filtered map with given context
t_map				*map_cfilter_new(t_map *map, t_cfilter_mfn f,
						void *context);

// Creates a map iterator for the map
t_map_iter			map_iter(t_map *map);

// Iterates over map to the next value
t_bool				map_iter_next(t_map_iter *iter);

#endif
