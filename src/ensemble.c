#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"


struct ensemble {
    unsigned int taille;
    unsigned int positions[WORLD_SIZE];
    
};


void positions_init( struct ensemble* pi ) {
    pi-> taille = 0 ;
}

void ajout_position(struct ensemble* p , int place ){
    p->positions[p->taille]=place ;
    p->taille+=1;
}


void black_list(struct ensemble* pw, struct world_t* w){
    for (int i=0 ; i< WORLD_SIZE ; i++){
        if (world_get(w,i)== "BLACK"){
            ajout_position( pw, i);
        }
    }
}
void white_list(struct ensemble* pb, struct world_t* w){
    for (int i=0 ; i< WORLD_SIZE ; i++){
        if (world_get(w,i)== "WHITE"){
            ajout_position( pb, i);
        }
    }
}

int place_visited (struct ensemble* ens, unsigned int place ){
    for (int i =0; i < ens->taille; i++){
        if (place == ens->positions[i]){
            return 0;
        }
    }
    return 1;
}

void concatener_ensembles(struct ensemble* a, struct ensemble* b ){
    for (int i=0 ; i < b->taille; i++){
        ajout_position( a , b->positions[i]);
    }
}



