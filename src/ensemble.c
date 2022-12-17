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

void ajout_position(struct ensemble* p ,unsigned int place ){
    p->positions[p->taille]=place ;
    p->taille+=1;
}


void black_list(struct ensemble* pw, struct world_t* w){
    positions_init(pw);
    for (int i=0 ; i< WORLD_SIZE ; i++){
        if (world_get(w,i) == 1){
            ajout_position( pw, i);
        }
    }
}

void white_list(struct ensemble* pb, struct world_t* w){
    positions_init(pb);
    for (int i=0 ; i< WORLD_SIZE ; i++){
        if (world_get(w,i) == 2){
            ajout_position( pb, i);
        }
    }
}

int place_visited(struct ensemble* ens, unsigned int place ){
    
    for (unsigned int i =0; i < ens->taille; i++){
        if (place == ens->positions[i]){
            return 1;
        }
    }
    return 0;
}

int element_commun(struct ensemble* ens, struct ensemble* ens2){
    for(unsigned int i = 0; i < ens->taille; i++){
        for(unsigned int j = 0; j < ens2->taille; j++){
            if (ens->positions[i] == ens2->positions[j]){
                return 1;
            }
        }
    }
    return 0;
}

void concatener_ensembles(struct ensemble* a, struct ensemble* b ){
    for (unsigned int i=0 ; i < b->taille; i++){
        ajout_position( a , b->positions[i]);
    }
}



int egalite_de_deux_ensembles(struct ensemble a,struct ensemble b){
    if (a.taille==b.taille){
        for (unsigned int i=0 ; i<a.taille ; i++){
            if (a.positions[i]!=b.positions[i]){
                return 0;
            }
        }
    }
    return 1 ;
}
