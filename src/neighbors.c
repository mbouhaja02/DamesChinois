#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"
#include <limits.h> 
#include "neighbors.h"


struct neighbors_t neighbors;


/** Initializes the relation between the neighbors, based on an
    integer `seed`. `seed` must be less than MAX_RELATIONS.
    Can be called multiple times. */
void init_neighbors(unsigned int seed){

}
  

/** Returns the neighbor of the place `idx`, in direction `d`, and
    UINT_MAX if there is no such neighbor (or any other kind of error) */
unsigned int get_neighbor(unsigned int idx, enum dir_t d){
    switch (d)
    {   int i=idx;
        case 1 :
            i++;
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
        default : return idx;
    return i ;
    }
}
/** Returns the list of the neighbors of the place `idx`, terminated
    by UINT_MAX.  */
struct neighbors_t get_neighbors(unsigned int idx)
{   struct neighbors_t jiran;
    for (int j=-4;j<5 ;j++){
        jiran[j]={get_neighbor(idx,j),;
    }
    return jiran;
}