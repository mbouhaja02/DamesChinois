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
/*calculons la distance parcourue par une pièce lors d'un déplacement donné:  la distance parcourue sera la difference des deux cases % WIDTH , 
pour chaque déplacement stocke dans un set les distances de chaque déplacement à chaque pièce dans l'set des indices de l'autre joueur
de la forme d'un tableau des tableaux avec l'indice du déplacement dans une case donnée donne accès à un tableau de distances on cherche le max 
dans tous les tableaux et on renvoie l'indice du tableaux qui contient le max ou on peut retenir que le max de chaque déplacement dès le début 
it'll be something like : */
/**unsigned int max_distance(struct game_t game){
    struct set* positions_of_player;
    struct set* md;
    struct set* distances;
    positions_init(distances);
    int max_distance_for_position = 0; 
    int max_distance_for_positions = 0; 
    unsigned int indice_maximal ;
    unsigned int max_position ;
    if (game.current_player = BLACK){
        white_list(positions_of_player, game.w)
    }
    else {
        black_list(positions_of_player, game.w)
    }

    available_movements(game , md);
    for (int mouvement = 0; mouvement < md->taille; mouvement++){
        for (int pions_adverses = 0; pions_adverses < positions_of_player->taille; pions_adverses++){
            max_distance_for_position = MAX(max_distance_for_position , md->position[mouvement]-positions_of_player->position[pions_adverses]);}
        max_distance_for_positions = MAX(max_distance_for_position, max_distance_for_positions ); 
        indice_maximale = max_distance_for_positions = max_distance_for_position ? md->position[]
    }
}**/ 
//Tableau de taill WORLD_SIZE**2
//this function calculates the distance between a and every other square in the world 
/**void distance( struct set* distances_of_a, int compteur){
    for (int )    
        distances_of_a->taille = WORLD_SIZE 
        distances_of_a->positions[a]= 0;
        struct neighbors_t neighbor = get_neighbors(a);
        compteur = compteur + 1;
        while compteur<WORLD_SIZE
        for (int i = 0; i<MAX_RELATIONS; i++){
            distances_of_a->positions[neighbor[i].i]=compteur;
            distance(i,distances_of_a,compteur);
        }      
    }
}

void distances(){
    for (int i = 0; i<WORLD_SIZE; i++){
        if (place_visited(distance_of_square,a)
        distance(i,)
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
void distances(int* distance,int cpt ){
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
}