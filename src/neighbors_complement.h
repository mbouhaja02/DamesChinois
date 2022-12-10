#ifndef __NEIGHBORS_COMPLEMENT_H__
#define __NEIGHBORS_COMPLEMENT_H__

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "neighbors_complement.h"
#include <limits.h>

/** The number of relations in the code */
#define MAX_RELATIONS 1
/** The maximum number of neighbors for a place */
#define MAX_NEIGHBORS 8

//function that adds a neighbor of idx_1 as a vector with place idx_2 and direction d 
void add_neighbor(unsigned int idx_1, unsigned int idx_2 ,enum dir_t d);


//function that initializes a simple board with 4 relations
void init_simple_board();

//function that initializes a diagonal board with 8 relations 
void init_diagonal_board();

//function that gives neighbors in case of a simple board
struct neighbors_t get_neighbors_for_simple_board(unsigned int idx);

//function that gets neighbors depending on seed
struct neighbors_t get_neighbors_for_board_type(unsigned int idx, unsigned int seed);


#endif 