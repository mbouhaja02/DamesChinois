#include <stdio.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"


struct neighbors_t neighbors[WORLD_SIZE];


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
        for(int j = 0; j < MAX_NEIGHBORS+1; j++){
            
            

            switch(i)   //lorsque le pawn est sur les corner
            {
                case 0:
                    add_neighbor(i, EAST);
                    add_neighbor(i, SOUTH);
                    break;
                case 9:
                    add_neighbor(i, WEST);
                    add_neighbor(i, SOUTH);
                    break;
                case 99:
                    add_neighbor(i, NORTH);
                    add_neighbor(i, WEST);
                    break;
                case 90:
                    add_neighbor(i, EAST);
                    add_neighbor(i, NORTH);
                    break;
                
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
}
/*L'initialisation de la board lorsque le seed!=0 en prend en considération les mouvements diagonales*/
void init_diagonal_board(){
    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < MAX_NEIGHBORS+1; j++){
            
            

            switch(i)
            {
                case 0:
                    add_neighbor(i, EAST);
                    add_neighbor(i, SOUTH);
                    add_neighbor(i, SEAST);
                    break;
                case 9:
                    add_neighbor(i, WEST);
                    add_neighbor(i, SOUTH);
                    add_neighbor(i, SWEST);
                    break;
                case 99:
                    add_neighbor(i, NORTH);
                    add_neighbor(i, WEST);
                    add_neighbor(i, NWEST);
                    break;
                case 90:
                    add_neighbor(i, EAST);
                    add_neighbor(i, NORTH);
                    add_neighbor(i, NEAST);
                    break;
                
            }
            if (i < 9 && i > 0){
                add_neighbor(i, EAST);
                add_neighbor(i, WEST);
                add_neighbor(i, SOUTH);
                add_neighbor(i, SEAST);
                add_neighbor(i, SWEST);
            }
            if (i > 90 && i < 99){
                add_neighbor(i, NORTH);
                add_neighbor(i, EAST);
                add_neighbor(i, WEST);
                add_neighbor(i, NWEST);
                add_neighbor(i, NEAST);

            }

            int d = i%10;

            if (d == 0){
                add_neighbor(i, EAST);
                add_neighbor(i, NORTH);
                add_neighbor(i, SOUTH);
                add_neighbor(i, NEAST);
                add_neighbor(i, SEAST);
            }

            if (d == 9){
                add_neighbor(i, WEST);
                add_neighbor(i, NORTH);
                add_neighbor(i, SOUTH);
                add_neighbor(i, SWEST);
                add_neighbor(i, NWEST);
            }
            else{
                add_neighbor(i, WEST);
                add_neighbor(i, NORTH);
                add_neighbor(i, SOUTH);
                add_neighbor(i, EAST);
                add_neighbor(i, SWEST);
                add_neighbor(i, NWEST);
                add_neighbor(i, NEAST);
                add_neighbor(i, SEAST);
            }

        
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

    else {
        init_diagonal_board();// on considère les mouvements diagonales
    }
}

/** Returns the neighbor of the place `idx`, in direction `d`, and
    UINT_MAX if there is no such neighbor (or any other kind of error) */
unsigned int get_neighbor(unsigned int idx, enum dir_t d){
    switch (d)
    {   
        case 1 :
            idx++;
            break;
        case 2 : 
            idx=idx-WIDTH+1;
            break;
        case 3 : 
            idx=idx-WIDTH;
            break;
        case 4 : 
            idx=idx-WIDTH-1;
            break;
        case -1 : 
            idx=idx-1;
            break;
        case -2 : 
            idx=idx-1+WIDTH;
            break;
        case -3: 
            idx=idx+WIDTH;
            break;
        case -4 : 
            idx=idx+1+WIDTH;
            break;
        default : return idx;
    
    }
    return idx ;
}

/** Returns the list of the neighbors of the place `idx`, terminated
    by UINT_MAX.  */
struct neighbors_t get_neighbors(unsigned int idx) {   
    
    return neighbors[idx];
}