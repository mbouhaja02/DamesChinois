#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ensemble.h"
#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "movements.h"








void positions_init(struct ensemble* pi ) {
    pi->taille = 0 ;
}

/* On ajoute une positions place à un ensemble p */ 
void add_position(struct ensemble* p ,unsigned int place ){
    p->positions[p->taille]=place ;
    p->taille+=1;
}


/*Fill a set with all the black pieces*/
void black_list(struct ensemble* pw, struct world_t* w){
    positions_init(pw);
    for (int i=0 ; i< WORLD_SIZE ; i++){
        if (world_get(w,i) == 1){
            add_position( pw, i);
        }
    }
}

/*Fill a set with all the white pieces*/
void white_list(struct ensemble* pb, struct world_t* w){
    positions_init(pb);
    for (int i=0 ; i< WORLD_SIZE ; i++){
        if (world_get(w,i) == 2){
            add_position( pb, i);
        }
    }
}

/*Return 1 if place exists in set p or 0 if not*/
int place_visited(struct ensemble* ens, unsigned int place ){
    
    for (unsigned int i =0; i < ens->taille; i++){
        if (place == ens->positions[i]){
            return 1;
        }
    }
    return 0;
}

/*Return 1 if there's one element common between set et set2*/
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

/*Concatenate two sets*/
void concatenate_sets(struct ensemble* a, struct ensemble* b ){
    for (unsigned int i=0 ; i < b->taille; i++){
        add_position( a , b->positions[i]);
    }
}



/*Return 1 if two sets are equal or 0 if not*/
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
