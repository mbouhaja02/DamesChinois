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
void init_simple_board(){

    // for i in range WORLD_SIZE :
        // if (pas sur le bord gauche) :
            // ajouter les relations à neighbors[i]...

        // if (pas sur le bord droit) :
            // ajouter les relations à neighbors[i]...

        // ajouter les relations communes à toutes les cases à neighbors[i]

    for(int i = 0; i < WORLD_SIZE; i++){
            
            
        //lorsque le pawn est sur les corner
        if (i == 0){
            add_neighbor(i, EAST);
            add_neighbor(i, SOUTH);
        }

        if (i == 9){
            add_neighbor(i, WEST);
            add_neighbor(i, SOUTH);

        }

        if (i == 90){
            add_neighbor(i, EAST);
            add_neighbor(i, NORTH);
        }

        if (i == 99){
            add_neighbor(i, NORTH);
            add_neighbor(i, WEST);
        }
        /*Quand le pawn est au dessus*/
        if (i < 9 && i > 0){
            add_neighbor(i, EAST);
            add_neighbor(i, WEST);
            add_neighbor(i, SOUTH);
            }
        /*Quand le pawn est au dessous*/
        if (i > 90 && i < 99){
            add_neighbor(i, NORTH);
            add_neighbor(i, EAST);
            add_neighbor(i, SOUTH);
        }

        int d = i%10;
        /*le pawn est à gauche*/
        if (d == 0){
            add_neighbor(i, EAST);
            add_neighbor(i, NORTH);
            add_neighbor(i, SOUTH);
        }
        /*le pawn est à droite*/
        if (d == 9){
            add_neighbor(i, WEST);
            add_neighbor(i, NORTH);
            add_neighbor(i, SOUTH);
        }
        /*lorsque le pawn est à l'interieure du board*/
        else{
            add_neighbor(i, WEST);
            add_neighbor(i, NORTH);
            add_neighbor(i, SOUTH);
            add_neighbor(i, EAST);
            
          
        
        }
    }
}
/*L'initialisation de la board lorsque le seed!=0 en prend en considération les mouvements diagonales*/

void init_diagonal_board(){
    for(int i = 0; i < WORLD_SIZE; i++){
       // lorsque le pawn est sur l'une des corner
        if (i == 0){
            add_neighbor(i, EAST);
            add_neighbor(i, SOUTH);
            add_neighbor(i, SEAST);
        }

        if (i == 9){
            add_neighbor(i, WEST);
            add_neighbor(i, SOUTH);
            add_neighbor(i, SWEST);
        }

        if (i == 90){
            add_neighbor(i, EAST);
            add_neighbor(i, NORTH);
            add_neighbor(i, NEAST);
        }

        if (i == 99){
            add_neighbor(i, NORTH);
            add_neighbor(i, WEST);
            add_neighbor(i, NWEST);
        }
        /*Quand le pawn est au dessus*/
        if (i < 9 && i > 0){
            add_neighbor(i, EAST);
            add_neighbor(i, WEST);
            add_neighbor(i, SOUTH);
            add_neighbor(i, SEAST);
            add_neighbor(i, SWEST);
            }
        /*Quand le pawn est au dessous*/
        if (i > 90 && i < 99){
            add_neighbor(i, NORTH);
            add_neighbor(i, EAST);
            add_neighbor(i, SOUTH);
            add_neighbor(i, NEAST);
            add_neighbor(i, SEAST);
        }

        int d = i%10;
        /*le pawn est à gauche*/
        if (d == 0 && i!=0 && i != 90){
            add_neighbor(i, EAST);
            add_neighbor(i, NORTH);
            add_neighbor(i, SOUTH);
            add_neighbor(i, NEAST);
            add_neighbor(i, SEAST);
        }
        /*le pawn est à droite*/
        if (d == 9 && i != 9 && i != 99){
            add_neighbor(i, WEST);
            add_neighbor(i, NORTH);
            add_neighbor(i, SOUTH);
            add_neighbor(i, NWEST);
            add_neighbor(i, SWEST);
        }
        /*lorsque le pawn est à l'interieure du board*/
        else{
            add_neighbor(i, WEST);
            add_neighbor(i, NORTH);
            add_neighbor(i, SOUTH);
            add_neighbor(i, EAST);
            add_neighbor(i, NWEST);
            add_neighbor(i, SWEST);
            add_neighbor(i, NEAST);
            add_neighbor(i, SEAST);
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
            else    
                return NO_DIR;
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
            else    
                return NO_DIR;
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
            else    
                return NO_DIR;
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
            else    
                return NO_DIR;
            break;
        case NW:
            if(d == EAST)
                return idx+1;
            if(d == SOUTH)
                return idx+WIDTH;
            if(d == SEAST)
                return idx+WIDTH+1;
            else    
                return NO_DIR;
            break;
        case NE:
            if(d == WEST)
                return idx-1;
            if(d == SOUTH)
                return idx+WIDTH;
            if(d == SWEST)
                return idx+WIDTH-1;
            else    
                return NO_DIR;
            break;
        case SW:
            if(d == EAST)
                return idx+1;
            if(d == NORTH)
                return idx-WIDTH;
            if(d == NEAST)
                return idx-WIDTH+1;
            else    
                return NO_DIR;
            break;
        case SE:
            if(d == WEST)
                return idx-1;
            if(d == NORTH)
                return idx-WIDTH;
            if(d == NWEST)
                return idx-WIDTH-1;
            else    
                return NO_DIR;
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
            else    
                return NO_DIR;
            break;

        default:
            break;
    }
    return -1;
}

/** Returns the list of the neighbors of the place `idx`, terminated
    by UINT_MAX.  */
struct neighbors_t get_neighbors(unsigned int idx) {   
    return neighbors[idx];
}