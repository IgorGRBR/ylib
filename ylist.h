/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:43:02 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 11:43:04 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YLIST_H
# define YLIST_H
# include "ytypes.h"
# ifndef LIST_C_STEP
#  define LIST_C_STEP 20
# endif

// Allocates and initializes an empty list
t_list		*list_new(void);

// Initializes an empty list
t_bool		list_init(t_list *list);

// Initializes a list as a copy of other list
t_bool		list_init_from_list(t_list *list, t_list *other);

// Private function! Reallocates the list to the new capacity
void		_list_realloc(t_list *list, unsigned int new_size);

// Deinitializes and deallocates the list itself (but not the elements)
void		list_delete(t_list *list);

// Deinitializes the list itself (but not the elements)
void		list_deinit(t_list *list);

// Insert the element to the back of the list
void		list_insert(t_list *list, void *e);

// Insert the element into the i-th place of the list
void		list_insert_at(t_list *list, unsigned int i, void *e);

// Remove element from the list
void		list_remove(t_list *list, void *e);

// Remove the i-th element from the list
void		list_remove_at(t_list *list, unsigned int i);

// Retrieve a value of i-th element of the list
void		*list_get(t_list *list, unsigned int i);

// Set a value of i-th element of the list
void		list_set(t_list *list, unsigned int i, void *element);

// Perform a shallow copy
t_list		*list_copy(t_list *list);

// Removes and returns the last element from the list 
void		*list_pop(t_list *list);

typedef void	(*t_apply_lfn)(void *);

// Apply a function to each list element
void		list_apply(t_list *list, t_apply_lfn f);

typedef void	*(*t_map_lfn)(void *);

// Build a new list by applying mapping function to a given list
t_list		*list_map(t_list *list, t_map_lfn f);

typedef t_bool	(*t_filter_lfn)(void *);

// Retaining-based filter
void		list_filter(t_list *list, t_filter_lfn f);

// Build a new, filtered list
t_list		*list_filter_new(t_list *list, t_filter_lfn f);

typedef void	(*t_iapply_lfn)(void *, unsigned int);

// Apply a function to each list element with indexes
void		list_iapply(t_list *list, t_iapply_lfn f);

typedef void	*(*t_imap_lfn)(void *, unsigned int);

// Build a new list by applying mapping function with index to a given list
t_list		*list_imap(t_list *list, t_imap_lfn f);

// A helper function to quickly free a single element using free from stdlib
// with index
void		free_list_element_i(void *e, unsigned int i);

typedef t_bool	(*t_ifilter_lfn)(void *, unsigned int);

// Retaining-based filter
void		list_ifilter(t_list *list, t_ifilter_lfn f);

// Build a new, filtered list
t_list		*list_ifilter_new(t_list *list, t_ifilter_lfn f);

typedef void	(*t_capply_lfn)(void *, void *);

// Apply a function to each list element
void		list_capply(t_list *list, t_capply_lfn f, void *context);

typedef void	*(*t_cmap_lfn)(void *, void *);

// Build a new list by applying mapping function to a given list
t_list		*list_cmap(t_list *list, t_cmap_lfn f, void *context);

typedef t_bool	(*t_cfilter_lfn)(void *, void *);

// Retaining-based filter
void		list_cfilter(t_list *list, t_cfilter_lfn f, void *context);

// Build a new, filtered list
t_list		*list_cfilter_new(t_list *list, t_cfilter_lfn f, void *context);

typedef void	(*t_icapply_lfn)(void *, unsigned int, void *);

// Apply a function to each list element with context
void		list_icapply(t_list *list, t_icapply_lfn f, void *context);

typedef void	*(*t_icmap_lfn)(void *, unsigned int, void *);

// Build a new list by applying mapping function to a given list with context
t_list		*list_icmap(t_list *list, t_icmap_lfn f, void *context);

typedef t_bool	(*t_icfilter_lfn)(void *, unsigned int, void *);

// Retaining-based filter with context
void		list_icfilter(t_list *list, t_icfilter_lfn f, void *context);

// Build a new, filtered list with context
t_list		*list_icfilter_new(t_list *list, t_icfilter_lfn f, void *context);

// Find an item inside a list using pointer equality
int			list_find_ptr(t_list *list, void *item);

// Find an item inside a list using equality function
int			list_find_eq(t_list *list, t_equals_func f, void *item);

// Creates a list iterator for the list
t_list_iter	list_iter(t_list *list);

// Creates a list iterator and points it to the first index of the list
t_list_iter	list_iter_first(t_list *list);

// Creates a list iterator and points it to the last index of the list
t_list_iter	list_iter_last(t_list *list);

// Iterates to the next value
t_bool		list_iter_next(t_list_iter *iter);

// Iterates to the previous value
t_bool		list_iter_prev(t_list_iter *iter);

// Sets iteration index to the start of the list
void		list_iter_begin(t_list_iter *iter);

// Sets iteration index to the end of the list
void		list_iter_end(t_list_iter *iter);

#endif
