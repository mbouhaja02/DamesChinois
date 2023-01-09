#ifndef __ENSEMBLE_H_
#define __ENSEMBLE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "world.h"

struct ensemble{
    unsigned int taille;
    unsigned int positions[WORLD_SIZE];
    
};

void positions_init(struct ensemble* pi);

/* On ajoute une positions place à un ensemble p */ 
void add_position(struct ensemble* p , unsigned int place );

/*Fill a set with all the black pieces*/
void black_list(struct ensemble* pw, struct world_t* w);

/*Fill a set with all the white pieces*/
void white_list(struct ensemble* pb, struct world_t* w);

/*Return 1 if place exists in set p or 0 if not*/
int place_visited (struct ensemble* p, unsigned int place );


/*Return 1 if there's one element common between set et set2*/
int common_element(struct ensemble* ens, struct ensemble* ens2);

/*Return 1 if two sets are equal or 0 if not*/
int equality_of_two_sets(struct ensemble a, struct ensemble b);

/*Concatenate two sets
void concatenate_sets(struct ensemble* a, struct ensemble* b )
*/
#endif 
