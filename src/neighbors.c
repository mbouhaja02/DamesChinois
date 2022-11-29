#include <stdio.h>
#include "geometry.h"
#include "neighbors.h"


struct neighbors_t neighbors;


/** Initializes the relation between the neighbors, based on an
    integer `seed`. `seed` must be less than MAX_RELATIONS.
    Can be called multiple times. */
 /*void init_neighbors(unsigned int seed){
   if ( seed < MAX_RELATIONS ) {
        neighbors ;
    }
  
}*/

/** Returns the neighbor of the place `idx`, in direction `d`, and
    UINT_MAX if there is no such neighbor (or any other kind of error) */
unsigned int get_neighbor(unsigned int idx, enum dir_t d){
    switch (d)
    {   ;
        case 1 :
            idx++;
            break;
        case 2 : 
            idx=idx-WIDTH+1;
            break;
        case 3 : 
            idx=idx-WIDTH;
            break;
        case 4 : 
            idx=idx-WIDTH-1;
            break;
        case -1 : 
            idx=idx-1;
            break;
        case -2 : 
            idx=idx-1+WIDTH;
            break;
        case -3: 
            idx=idx+WIDTH;
            break;
        case -4 : 
            idx=idx+1+WIDTH;
            break;
        default : return idx;
    return idx ;
    }
}
/** Returns the list of the neighbors of the place `idx`, terminated
    by UINT_MAX.  */
struct neighbors_t get_neighbors(unsigned int idx)
{   struct neighbors_t nbr;
    for ( enum dir_t j = SEAST; j < NWEST ;j++){
        nbr.n[j+4].i = get_neighbor(idx,j);
        nbr.n[j+4].d = j;
    }
    return nbr;
    
}