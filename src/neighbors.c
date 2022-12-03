#include <stdio.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"


struct neighbors_t neighbors[WORLD_SIZE];

enum place_board_t place_sur_board(unsigned int idx){
    if (idx == 0 )
        return NW;
    if (idx == 9)
        return NE;
    if (idx == 90)
        return SW;
    if (idx == 99)
        return SE;
    if (idx % 10 == 0)
        return W;
    if (idx%10 == 9)
        return E;
    if ( idx < 9 && idx >0)
        return N;
    if (idx < 99 && idx > 90)
        return S;
    else
        return MID;
}

/*ajoute un neighbors à la liste des neighbors et déplace {UINT_MAX, NO_DIR} vers la position suivante*/
void add_neighbor(unsigned int idx, enum dir_t d){
    int j = 0;
    
    while (j < WORLD_SIZE){
        if(neighbors[idx].n[j].i == UINT_MAX){
            neighbors[idx].n[j].i = get_neighbor(idx, d);
            neighbors[idx].n[j].d = d;
            neighbors[idx].n[j+1].i = UINT_MAX;
            neighbors[idx].n[j+1].d = NO_DIR;

            j = WORLD_SIZE;
        }
        j = j + 1;
    }
}


/*L'initialisation simple de la board lorsque le seed = 0 donc on distingue 9 cas possible*/
void init_diagonal_board(){

    init_simple_board();

    for(unsigned int i = 0; i < WORLD_SIZE; i++){
        enum place_board_t plt = place_sur_board(i);
        switch (plt){
            case N:
                add_neighbor(i, SEAST);
                add_neighbor(i, SWEST);
                break;

            case W:
                add_neighbor(i, NEAST);
                add_neighbor(i, SEAST);
                break;
            case E:
                add_neighbor(i, NWEST);
                add_neighbor(i, SWEST);
                break;
            case S:
                add_neighbor(i, NEAST);
                add_neighbor(i, SEAST);
                break;
            case NW:
                add_neighbor(i, SEAST);
                break;
            case NE:
                add_neighbor(i, SWEST);
                break;
            case SW:
                add_neighbor(i, NEAST);
                break;
            case SE:
                add_neighbor(i, NWEST);
                break;
            case MID:
                add_neighbor(i, NWEST);
                add_neighbor(i, SWEST);
                add_neighbor(i, NEAST);
                add_neighbor(i, SEAST);
                break;

            default:
                break;
        }
        
    }
    
}

void init_simple_board(){

    // for i in range WORLD_SIZE :
        // if (pas sur le bord gauche) :
            // ajouter les relations à neighbors[i]...

        // if (pas sur le bord droit) :
            // ajouter les relations à neighbors[i]...

        // ajouter les relations communes à toutes les cases à neighbors[i]

    for(unsigned int i = 0; i < WORLD_SIZE; i++){
        enum place_board_t plt = place_sur_board(i);
        switch (plt){

        
            case N:
                add_neighbor(i, EAST);
                add_neighbor(i, WEST);
                add_neighbor(i, SOUTH);
       
                break;

            case W:
                add_neighbor(i, EAST);
                add_neighbor(i, NORTH);
                add_neighbor(i, SOUTH);
         
                break;
            case E:
                add_neighbor(i, WEST);
                add_neighbor(i, NORTH);
                add_neighbor(i, SOUTH);
               
                break;
            case S:
                add_neighbor(i, NORTH);
                add_neighbor(i, EAST);
                add_neighbor(i, SOUTH);
                
                break;
            case NW:
                add_neighbor(i, EAST);
                add_neighbor(i, SOUTH);
                
                break;
            case NE:
                add_neighbor(i, WEST);
                add_neighbor(i, SOUTH);
                
                break;
            case SW:
                add_neighbor(i, EAST);
                add_neighbor(i, NORTH);
                
                break;
            case SE:
                add_neighbor(i, NORTH);
                add_neighbor(i, WEST);

                break;
            case MID:
                add_neighbor(i, WEST);
                add_neighbor(i, NORTH);
                add_neighbor(i, SOUTH);
                add_neighbor(i, EAST);
                
                break;

            default:
                break;
        }
        
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
        for(int j = 1; j < MAX_NEIGHBORS+1; j++){
            
            neighbors[i].n[j].i = 0;
            neighbors[i].n[j].d = 0;
        }
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
    enum place_board_t plt = place_sur_board(idx);
    switch (plt)
    {
        case N:
            if(d == EAST)
                return idx+1;
            if(d == SOUTH)
                return idx+WIDTH;
            if(d == SEAST)
                return idx+WIDTH+1;
            if(d == SWEST)
                return idx+WIDTH-1;
            if(d == WEST)
                return idx-1;
            
            break;

        case W:
            if(d == EAST)
                return idx+1;
            if(d == SOUTH)
                return idx+WIDTH;
            if(d == SEAST)
                return idx+WIDTH+1;
            if(d == NORTH)
                return idx-WIDTH;
            if(d == NEAST)
                return idx-WIDTH+1;
            
            break;
        case E:
            if(d == WEST)
                return idx-1;
            if(d == SOUTH)
                return idx+WIDTH;
            if(d == SWEST)
                return idx+WIDTH-1;
            if(d == NORTH)
                return idx-WIDTH;
            if(d == NWEST)
                return idx-WIDTH-1;
           
            break;
        case S:
            if(d == EAST)
                return idx+1;
            if(d == WEST)
                return idx-1;
            if(d == NWEST)
                return idx-WIDTH-1;
            if(d == NORTH)
                return idx-WIDTH;
            if(d == NEAST)
                return idx-WIDTH+1;
         
            break;
        case NW:
            if(d == EAST)
                return idx+1;
            if(d == SOUTH)
                return idx+WIDTH;
            if(d == SEAST)
                return idx+WIDTH+1;

            break;
        case NE:
            if(d == WEST)
                return idx-1;
            if(d == SOUTH)
                return idx+WIDTH;
            if(d == SWEST)
                return idx+WIDTH-1;

            break;
        case SW:
            if(d == EAST)
                return idx+1;
            if(d == NORTH)
                return idx-WIDTH;
            if(d == NEAST)
                return idx-WIDTH+1;
       
            break;
        case SE:
            if(d == WEST)
                return idx-1;
            if(d == NORTH)
                return idx-WIDTH;
            if(d == NWEST)
                return idx-WIDTH-1;
     
            break;
        case MID:
            if(d == WEST)
                return idx-1;
            if(d == NORTH)
                return idx-WIDTH;
            if(d == NWEST)
                return idx-WIDTH-1;
            if(d == EAST)
                return idx+1;
            if(d == NEAST)
                return idx-WIDTH+1;
  
            break;

        default:
            return UINT_MAX;
            break;
    }
}

/** Returns the list of the neighbors of the place `idx`, terminated
    by UINT_MAX.  */
struct neighbors_t get_neighbors(unsigned int idx) {   
    return neighbors[idx];
}