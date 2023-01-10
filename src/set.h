 #ifndef __set_H_
#define __set_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "world.h"

//This structure helps create a set that will be used to stock positions and the number of positions in the set
struct set{
    unsigned int taille;
    unsigned int positions[WORLD_SIZE];
    
};

//Initializes a set
void positions_init(struct set* pi);

//Add a position to a set
void add_position(struct set* p , unsigned int place );

//Fill a set with the positions of black pieces in the world
void black_list(struct set* pw, struct world_t* w);

//Fill a set with the position of white pieces in the world
void white_list(struct set* pb, struct world_t* w);

//Verify the existence of a place in a set  and return 1 if it does 0 if it doesn't
int place_visited (struct set* p, unsigned int place );


//If two sets have a common element the function returns 1 return 0 otherwise
int common_element(struct set* ens, struct set* ens2);

//Verifies if two sets are alike
int equality_of_two_sets(struct set a, struct set b);


#endif 