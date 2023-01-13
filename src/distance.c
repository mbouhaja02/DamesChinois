#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "geometry.h"
#include "world.h"
#include "neighbors.h"
#include "set.h"
#include "movements.h"
#include "distance.h"

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
//Achievement4
//this function calculates the distance between a and every other square in the world 

/*void distance( struct set* distances_of_a, unsigned int a ,int compteur){    
        struct neighbors_t neighbor = get_neighbors(a);
        compteur = compteur + 1;
        while compteur<WORLD_SIZE
                for (int i = 0; i<MAX_RELATIONS; i++){
                    distances_of_a->positions[neighbor[i].i]=compteur;
                    distance(i,distances_of_a,compteur);
        }      
    }
}

void distances(unsigned int a, unsigned int position){
    for (int i = 0; i<WORLD_SIZE; i++){
        if (place_visited(distance_of_square,a) == 0){
            distance(i,)
        }
    }
}       

unsigned int closest_to_set(unsigned int a, struct set set ){
    unsigned int space = WORLD_SIZE ; 
    for (int i = 0; i < set.taille; i++){
        if (MIN(space, distance(a, set.positions[i]))!=space){
            space = distance( a, set.positions[i]);
        }
    }
    return space;
}

unsigned int closest_in_set1_to_set2(struct set set1, struct set set2){
    unsigned int idx = 0;
    int space = WORLD_SIZE;
    for (int i = 0; i < set1.taille; i++){
        if (MIN(closest_to_set(set1.positions[i], set2),space)!= space){
            space = closest_to_set(set1.positions[i], set2);
            idx = set1.positions[i];
        }
    }
    return idx ;
}

unsigned int closest_movement_to_other_player(struct game_t game){
    struct set positions_of_player;
    struct set md;
    if (game.current_player = BLACK){
        white_list(&positions_of_player, game.w);
    }
    else {
        black_list(&positions_of_player, game.w);
    }
    available_movements(game , &md);
    return closest_in_set1_to_set2(md, positions_of_player);
}**/


/*On crée un tableau de taille WORLD_SIZE**2 (représente une matrice symétrique)*/
/*void distances(int* distance,int cpt ){
    struct neighbors_t neighbors;
    for (unsigned int i = 0; i<WORLD_SIZE ; i++){ //i line indicator
        neighbors = get_neighbors(i);
        for (unsigned int j=i+1; j < WORLD_SIZE ;j++ ){ //j is column indicator , distance between i and j is the same as j and i 
            distance[i*WORLD_SIZE+j]= distance[i*WORLD_SIZE+j] + 1 ;
            distance[j*WORLD_SIZE+i]= distance[j*WORLD_SIZE+i] + 1;
            if (is_neighbor(neighbors,j)==0 && cpt<2) {
                cpt++;
                distances(distance,cpt);
            }
        }
    }
}*/

int distance(unsigned int a , unsigned int b){
    int d ;
    struct neighbors_t neighbors = get_neighbors(a);
    if (is_neighbor(a,b)!=0){
        return 1;
    }
    else {
        int i=0;
        while(neighbors.n[i].i!= UINT_MAX && d<WORLD_SIZE){
            d = MIN(d,distance(neighbors.n[i].i,b))+1;
            printf("%d\n",WORLD_SIZE);
            printf("%d\t",d);
            i++;
        }
    }
    return d;
}
   
