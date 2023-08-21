// TODO: Add 42 School header here

#include "ytypes.h"

// Create and initialize a new empty map
t_map	*map_new(t_hash_func hfunc, t_equals_func efunc);

// Initialize a new empty map
t_bool	map_init(t_map *map, t_hash_func hfunc, t_equals_func efunc);

// Deinitialize and delete a map
void	map_delete(t_map *map);

// Deinitialize a map
void	map_deinit(t_map *map);
