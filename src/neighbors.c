<<<<<<< HEAD
#include "geometry.h"
#include <limits.h>
#include "neighbors.h"

typedef struct vector_t vect ;

void init_neighbors(unsigned int seed) {
    if (seed < MAX_RELATIONS ){
        vect neighbor=n[seed];

    }
}
unsigned int get_neighbor(unsigned int idx, enum dir_t d){
    
}
struct neighbors_t get_neighbors(unsigned int idx);
=======
#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"
#include <limits.h> 
#include "neighbors.h"

typedef struct neighbors_t neighbor ; 
 ; 


void init_neighbors(unsigned int seed)
{ 
    if (seed < MAX_RELATIONS )
    { 
        neighbor g ; 
    }
}

unsigned int get_neighbor(unsigned int idx, enum dir_t d)
{   
    neighbor n;
    
    return 
}
>>>>>>> b5e1fa5d20a94e9d0b9e8906809ec5f5ec7e89fb
