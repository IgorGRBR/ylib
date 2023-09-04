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

// Insert item with key into the map if it doesn't exist. Returns FALSE if
// item exists, otherwise returns TRUE
t_bool	map_insert(t_map *map, void *key, void *item);

// Sets the value of map at specified key to the item
void	map_set(t_map *map, void *key, void *item);

// Retrieves item from the map by the specified key
void	*map_get(t_map *map, void *key);
