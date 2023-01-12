#include <stdio.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"





struct neighbors_t neighbors[WORLD_SIZE];


/** Returns the neighbor of the place `idx`, in direction `d`, and
    UINT_MAX if there is no such neighbor (or any other kind of error) */
unsigned int get_neighbor(unsigned int idx, enum dir_t d){
    unsigned int i = idx;
    switch (d)
    {   
        case 1 :
            i = i + 1;
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
    return i ;
    
}

//This function verifies if it is accesible for an idx to move to a neighbor
int existence_of_neighbor(unsigned int idx , unsigned int neighbor){
    int j = 0;
    while (neighbors[idx].n[j].i!=UINT_MAX){
        if (neighbors[idx].n[j].i == neighbor){
            return 1 ;
        }
        j++;
    }
    return 0;
}

/*ajoute un neighbors à la liste des neighbors et déplace {UINT_MAX, NO_DIR} vers la position suivante*/
void add_neighbor(unsigned int idx_1, unsigned int idx_2, enum dir_t d){
        for(int j = 0; j < MAX_NEIGHBORS; j++){
            if(neighbors[idx_1].n[j].i == UINT_MAX){
                neighbors[idx_1].n[j].i = idx_2;
                neighbors[idx_1].n[j].d = d;
                neighbors[idx_1].n[j+1].i = UINT_MAX;
                neighbors[idx_1].n[j+1].d = NO_DIR;
                break;
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

//function that initializes a diagonal board with 8 relations 
void init_diagonal_board(){

    init_simple_board();

    for (int i = 0 ; i < WORLD_SIZE ; i++){
        if (i >= WIDTH && i%WIDTH != 0) {
            add_neighbor(i,get_neighbor(i,NWEST),NWEST);
            }

        if ( i< WORLD_SIZE - WIDTH && i%WIDTH != 0){
            add_neighbor(i, get_neighbor(i, SWEST),SWEST);
            
            }
        if (i >= WIDTH && i%WIDTH != WIDTH - 1){
            add_neighbor(i, get_neighbor(i, NEAST),NEAST);
            }

        if (i< WORLD_SIZE - WIDTH && i%WIDTH != WIDTH - 1){
            add_neighbor(i , get_neighbor(i, SEAST),SEAST);
            }
    } 
}

void init_triangular_board(){

    init_simple_board();

    for (int i = 0 ; i < WORLD_SIZE ; i++){
        if (i< WORLD_SIZE - WIDTH && i%WIDTH != WIDTH - 1){
            add_neighbor(i , get_neighbor(i, SEAST),SEAST);
            }
    } 
}

void init_hexagonal_board(){
    for (int i = 0 ; i < WORLD_SIZE ; i++){
        if (i%2 == 0){
            if (i%WIDTH != WIDTH - 1){
                add_neighbor(i , get_neighbor(i, EAST),EAST);}
            if (i%WIDTH != 0){
                add_neighbor(i, get_neighbor(i, WEST),WEST);}
        }
        else { 
            if (i >= WIDTH && i%WIDTH != 0) {
                add_neighbor(i,get_neighbor(i,NWEST),NWEST);
            }

            if ( i< WORLD_SIZE - WIDTH && i%WIDTH != 0){
                add_neighbor(i, get_neighbor(i, SWEST),SWEST);
            
            }
            if (i >= WIDTH && i%WIDTH != WIDTH - 1){
                add_neighbor(i, get_neighbor(i, NEAST),NEAST);
            }

            if (i< WORLD_SIZE - WIDTH && i%WIDTH != WIDTH - 1){
                add_neighbor(i , get_neighbor(i, SEAST),SEAST);
            }

        }
    }

}  

/**Initializes the relation between the neighbors, based on an
    integer `seed`. `seed` must be less than MAX_RELATIONS.
    Can be called multiple times. */
void init_neighbors(unsigned int seed){

    // mettre tous les neighbors = à {{UINT, NO_DIR}, {0, 0 }....};
    
    for(int i =0; i < WORLD_SIZE; i++){
        neighbors[i].n[0].i = UINT_MAX;
        neighbors[i].n[0].d = NO_DIR;
    }
    switch (seed)
    {
    case 0:
        init_simple_board();
        break;
    case 1 : 
        init_diagonal_board();
        break;
    case 2 :
        init_triangular_board();
        break;
    case 3 : 
        init_hexagonal_board();
        break;
    default:
        break;
    }
}



/** Returns the list of the neighbors of the place `idx`, terminated
    by UINT_MAX.  */
struct neighbors_t get_neighbors(unsigned int idx) {
    return neighbors[idx];
}

//Verify if a case is a neighbor
int is_neighbor(struct neighbors_t neighbors , unsigned int idx){
    for (int j=0; j< MAX_NEIGHBORS; j++)
        if (neighbors.n[j].i== idx){
            return 1;
        }
    return 0;
}


//initializes triangular board not having acess to some places located outside its frame 
/**void init_triangular_neighbors(){
    unsigned int line ; 
    unsigned int right_limit ; 
    unsigned int left_limit ; 
    if (WIDTH > HEIGHT){
        for (unsigned int i = 0; i < WORLD_SIZE; i++){
            line = i/WIDTH ;
            right_limit = line*WIDTH + line ; 
            left_limit = (line+1)*WIDTH - HEIGHT + line;

            if (i > right_limit){
                add_neighbor(i, get_neighbor(i,WEST),WEST);
            }
            if (i < left_limit){
                add_neighbor(i, get_neighbor(i,EAST),EAST);
            }
            if (line != 0 && i < left_limit + 1 && i+1 > right_limit ){
                add_neighbor(i, get_neighbor(i,NORTH),NORTH);
            }
            if (line != HEIGHT-1 && i < left_limit +1 && i+1 > right_limit ){
                add_neighbor(i, get_neighbor(i,SOUTH),SOUTH);
            }
        }
    }
}**/







