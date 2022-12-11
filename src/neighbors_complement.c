
#include <stdio.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "neighbors_complement.h"

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

//function that initializes a diagonal board with 8 relations 
void init_diagonal_board(){

    init_simple_board();
    for (int i = 0 ; i < WORLD_SIZE ; i++){
        if (i >= WIDTH && i%WIDTH != 0) {
            add_neighbor(i,get_neighbor(i,NWEST),NWEST);}
        if ( i< WORLD_SIZE - WIDTH && i%WIDTH != 0){
            add_neighbor(i, get_neighbor(i, SWEST),SWEST);}
        if (i >= WIDTH && i%WIDTH != WIDTH - 1){
            add_neighbor(i, get_neighbor(i, NEAST),NEAST);}
        if (i< WORLD_SIZE - WIDTH && i%WIDTH != WIDTH - 1){
            add_neighbor(i , get_neighbor(i, SEAST),SEAST);}
    } 
}



   
    
}

//function that initializes a simple board with 4 relations

void init_simple_board(){


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

//function that get only simple board neighbors
struct neighbors_t get_neighbors_for_simple_board(unsigned int idx){
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        if (j==1 || j==3 || j==-1||j==-3){
            add_neighbor(idx,get_neighbor(idx,j),j);
        }
    }
}

//function that gets neighbors depending on seed
struct neighbors_t get_neighbors_for_board_type(unsigned int idx,unsigned int seed);
    switch (seed)
    {
    case 0:
        get_neighbors_for_simple_board(idx);
        break;
    case 1 : 
        get_neighbors(idx);
        break ;
    default:
        init_neighbors();
        break;
    }