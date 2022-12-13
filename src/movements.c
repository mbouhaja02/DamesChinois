#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "partie.h"



struct neighbors_t neighbors[WORLD_SIZE];


/* Fonction qui retourne l'ensemble des déplacements simple possible */
void deplacements_simple( struct game_t game, struct ensemble* ds ){
    unsigned int neighbor;
    enum sort_t b;
    int j = 0 ; 
    positions_init(ds);
    init_neighbors(game.seed);
    while (neighbors[game.position].n[j].i != UINT_MAX){
        neighbor = neighbors[game.position].n[j+4].i;
        b = world_get_sort(game.w, neighbor);
        if ( b == NO_SORT){
            ajout_position(ds,neighbor) ;
        }
        j++ ;
    }
        
}

/* Fonction qui retourne l'ensemble des sauts simples */
void saut_simple(struct game_t game , struct ensemble* ss){
    unsigned int neighbor;
    unsigned int neighbor_of_neighbor;
    int j=0; 
    init_neighbors(game.seed);
    while (neighbors[game.position].n[j].i != UINT_MAX){
        neighbor = neighbors[game.position].n[j].i;
        if (neighbors[neighbor].n[j].i != UINT_MAX){
            neighbor_of_neighbor = neighbors[neighbor].n[j+4].i;
            if ((world_get_sort(game.w , neighbor_of_neighbor ) == NO_SORT) && (world_get_sort(game.w , neighbor ) == PAWN)){
                ajout_position( ss , neighbor_of_neighbor);
            }
        }
    }
}

/* Fonction qui retourne l'ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) */
void saut_multiple(struct game_t game , struct ensemble* sm  ){
    saut_simple( game, sm);
        for (unsigned int i = 0 ; i < sm->taille ; i++){
            game.position = sm->positions[i];
            if(place_visited ( sm, game.position ) == 0){
                saut_multiple(game , sm);
        }
    } 
}

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
void mvts_disponibles (struct game_t game, struct ensemble* md) 
{  
    positions_init(md);
    deplacements_simple( game , md );
    printf("#\n");
    saut_multiple( game , md );
    printf("#\n");
}
/* Fonction qui retourne l'ensemble des mouvements possibles pour la tour*/
struct ensemble translation_cardinal(struct world_t* w, unsigned int idx){
    struct ensemble ens;
    positions_init(&ens);
    enum dir_t tab_dir[4] = {EAST, WEST, NORTH, SOUTH};
    for(int i =0; i < 4; i++){
        unsigned int idx2 = get_neighbor(idx, tab_dir[i]);
        while(world_get_sort(w, idx2) == 0){
            ajout_position(&ens, idx2);
            idx2 = get_neighbor(idx2, tab_dir[i]);
        }
    }
    return ens;
}

/* Fonction qui retourne l'ensemble des mouvements possibles pour l'éléphant*/
struct ensemble saut_semi_diagonal(struct world_t* w, unsigned int idx){
    struct ensemble ens;
    positions_init(&ens);
    enum dir_t tab_dir[4] = {NEAST, NWEST, SEAST, SWEST};
    for(int i =0; i < 4; i++){
        unsigned int idx2 = get_neighbor(idx, tab_dir[i]);
        while(world_get_sort(w, idx2) == NO_SORT){
            ajout_position(&ens, idx2);
            idx2 = get_neighbor(idx2, tab_dir[i]);
        }
    }
    return ens;
}
