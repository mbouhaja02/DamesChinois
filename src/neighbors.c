#include <stdio.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"


struct neighbors_t neighbors[WORLD_SIZE];


/*ajoute un neighbors à la liste des neighbors et déplace {UINT_MAX, NO_DIR} vers la position suivante*/
void add_neighbor(unsigned int idx_1, unsigned int idx_2, enum dir_t d){
    int j = 0;

    while (j < WORLD_SIZE){
        if(neighbors[idx_1].n[j].i == UINT_MAX){
            neighbors[idx_1].n[j].i = idx_2;
            neighbors[idx_1].n[j].d = d;
            neighbors[idx_1].n[j+1].i = UINT_MAX;
            neighbors[idx_1].n[j+1].d = NO_DIR;

            j = WORLD_SIZE;
        }
        j = j + 1;
    }
}


/*L'initialisation simple de la board lorsque le seed = 0 donc on distingue 9 cas possible*/
void init_diagonal_board(){

    init_simple_board();

   
    
}

void init_simple_board(){

    // for i in range WORLD_SIZE :
        // if (pas sur le bord gauche) :
            // ajouter les relations à neighbors[i]...

        // if (pas sur le bord droit) :
            // ajouter les relations à neighbors[i]...

        // ajouter les relations communes à toutes les cases à neighbors[i]
    for (int i = 0 ; i < WORLD_SIZE ; i++){
        if (i >= WIDTH ) {
            add_neighbor(i,get_neighbor(i,NORTH),NORTH);}
        if ( i< WORLD_SIZE - WIDTH){
            add_neighbor(i, get_neighbor(i, SOUTH),SOUTH);}
        if (i%WIDTH != 0){
            add_neighbor(i, get_neighbor(i, WEST),WEST);}
        if (i%WIDTH != WIDTH - 1){
            add_neighbor(i , get_neighbor(i, EAST),EAST);}
    } 
}




/** Initializes the relation between the neighbors, based on an
    integer `seed`. `seed` must be less than MAX_RELATIONS.
    Can be called multiple times. */
void init_neighbors(unsigned int seed){

    // mettre tous les neighbors = à {{UINT, NO_DIR}, {0, 0 }....};
    
    for(int i =0; i < WORLD_SIZE; i++){
        neighbors[i].n[0].i = UINT_MAX;
        neighbors[i].n[0].d = NO_DIR;
    }
    
    if (seed == 0) {
        init_simple_board();// on considère que les mouvements simples
    }
    else{
        init_diagonal_board();
    }
}

/** Returns the neighbor of the place `idx`, in direction `d`, and
    UINT_MAX if there is no such neighbor (or any other kind of error) */
unsigned int get_neighbor(unsigned int idx, enum dir_t d){
    unsigned int i = idx;
    switch (d)
    {   
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
        default : ;
    }
    
    
}

/** Returns the list of the neighbors of the place `idx`, terminated
    by UINT_MAX.  */
struct neighbors_t get_neighbors(unsigned int idx) {   
    return neighbors[idx];
}