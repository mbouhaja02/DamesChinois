#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ensemble.h"
#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "movements.h"







//Initializes a set
void positions_init(struct ensemble* pi ) {
    pi->taille = 0 ;
}

//Add a position to a set
void add_position(struct ensemble* p ,unsigned int place ){
    p->positions[p->taille]=place ;
    p->taille+=1;
}


//Fill a set with the positions of black pieces in the world
void black_list(struct ensemble* pw, struct world_t* w){
    positions_init(pw);
    for (int i=0 ; i< WORLD_SIZE ; i++){
        if (world_get(w,i) == 1){
            add_position( pw, i);
        }
    }
}

//Fill a set with the position of white pieces in the world
void white_list(struct ensemble* pb, struct world_t* w){
    positions_init(pb);
    for (int i=0 ; i< WORLD_SIZE ; i++){
        if (world_get(w,i) == 2){
            add_position( pb, i);
        }
    }
}

//Verify the existence of a place in a set  and return 1 if it does 0 if it doesn't
int place_visited(struct ensemble* ens, unsigned int place ){
    
    for (unsigned int i =0; i < ens->taille; i++){
        if (place == ens->positions[i]){
            return 1;
        }
    }
    return 0;
}

//If two sets have a common element the function returns 1 return 0 otherwise
int common_element(struct ensemble* ens, struct ensemble* ens2){
    for(unsigned int i = 0; i < ens->taille; i++){
        for(unsigned int j = 0; j < ens2->taille; j++){
            if (ens->positions[i] == ens2->positions[j]){
                return 1;
            }
        }
    }
    return 0;
}

//Concatenate two sets
void concatenate_sets(struct ensemble* a, struct ensemble* b ){
    for (unsigned int i=0 ; i < b->taille; i++){
        add_position( a , b->positions[i]);
    }
}



//Verifies if two sets are alike
int equality_of_two_sets(struct ensemble a,struct ensemble b){
    unsigned int m = 0;
    for(unsigned int i = 0; i < a.taille; i++){
        for(unsigned int j = 0; j < b.taille; j++){
            if(a.positions[i] == b.positions[j]){
                m++;
            }
        }
    }
    if(m == b.taille){
        return 1;
    }
    
    return 0 ;
}
