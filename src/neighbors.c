#include <stdio.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "neighbors_complement.h"





/** Initializes the relation between the neighbors, based on an
    integer `seed`. `seed` must be less than MAX_RELATIONS.
    Can be called multiple times. */
void init_neighbors(unsigned int seed){

    // mettre tous les neighbors = à {{UINT, NO_DIR}, {0, 0 }....};
    
    for(int i =0; i < WORLD_SIZE; i++){
        neighbors[i].n[0].i = UINT_MAX;
        neighbors[i].n[0].d = NO_DIR;
    }
    
    if (seed == 0) {
        init_simple_board();// on considère que les mouvements simples
    }
    else{
        init_diagonal_board();
    }
}

/** Returns the neighbor of the place `idx`, in direction `d`, and
    UINT_MAX if there is no such neighbor (or any other kind of error) */
unsigned int get_neighbor(unsigned int idx, enum dir_t d){
    unsigned int i = idx;
    switch (d)
    {   
        case 1 :
            i = i + 1;
            break;
        case 2 : 
            i=i-WIDTH+1;
            break;
        case 3 : 
            i=i-WIDTH;
            break;
        case 4 : 
            i=i-WIDTH-1;
            break;
        case -1 : 
            i=i-1;
            break;
        case -2 : 
            i=i-1+WIDTH;
            break;
        case -3: 
            i=i+WIDTH;
            break;
        case -4 : 
            i=i+1+WIDTH;
            break;
        default : ;
    }
    return i ;
    
}

/** Returns the list of the neighbors of the place `idx`, terminated
    by UINT_MAX.  */
struct neighbors_t get_neighbors(unsigned int idx) {   
    return neighbors[idx];
}