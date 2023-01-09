#ifndef __ENSEMBLE_H_
#define __ENSEMBLE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "world.h"

//This structure helps create a set that will be used to stock positions and the number of positions in the set
struct ensemble{
    unsigned int taille;
    unsigned int positions[WORLD_SIZE];
    
};

//Initializes a set
void positions_init(struct ensemble* pi);

//Add a position to a set
void add_position(struct ensemble* p , unsigned int place );

//Fill a set with the positions of black pieces in the world
void black_list(struct ensemble* pw, struct world_t* w);

//Fill a set with the position of white pieces in the world
void white_list(struct ensemble* pb, struct world_t* w);

//Verify the existence of a place in a set  and return 1 if it does 0 if it doesn't
int place_visited (struct ensemble* p, unsigned int place );


//If two sets have a common element the function returns 1 return 0 otherwise
int common_element(struct ensemble* ens, struct ensemble* ens2);

//Verifies if two sets are alike
int equality_of_two_sets(struct ensemble a, struct ensemble b);


#endif 
