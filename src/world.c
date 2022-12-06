#include <stdio.h>
#include <limits.h> 
#include "world.h"
#include "geometry.h"



static struct world_t w;

/** Initializes a world (NO_COLOR, NO_SORT everywhere)
    Always returns the same pointer */
struct world_t* world_init() {
    
    // mettre tous les éléments du tableau à NO_COLOR, NO_SORT
    return &w;
}

/** Return the color at a place */
enum color_t world_get(const struct world_t* b, unsigned int idx){
    enum color_t c = b->positions[idx][0];
    return c;
}

/** Sets the color at a place */
void world_set(struct world_t* b, unsigned int idx, enum color_t c){
    b->positions[idx][0] = c;
}

/** Return the sort at a place */
enum sort_t world_get_sort(const struct world_t* b, unsigned int idx){
    return b->positions[idx][1];
}

/** Sets the sort at a place */
void world_set_sort(struct world_t* b, unsigned int idx, enum sort_t c){
    b->positions[idx][1] = c;
}
