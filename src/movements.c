#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "partie.h"





/* Fonction qui retourne l'ensemble des déplacements simple possible */
void deplacements_simple( struct game_t game, struct ensemble* ds ){
    unsigned int gn;
    enum sort_t b;
    positions_init(ds);
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        if (game.seed == 0){
            if (j==1 || j==3 || j==-1||j==-3){
                gn = get_neighbor(game.position , j);
                b = world_get_sort(game.w, gn);
                if ( b == NO_SORT){
                ajout_position( ds , gn);}
            }
        
        else 
            gn = get_neighbor(game.position , j);
            b = world_get_sort(game.w, gn);
            if ( b == NO_SORT){
            ajout_position( ds , gn);
            }
        }    
    }

}
/* Fonction qui retourne l'ensemble des sauts simples */
void saut_simple(struct game_t game , struct ensemble* ss, ){
    unsigned int neighbor;
    unsigned int neighbor_of_neighbor; 
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        if (game.seed = 0){
            if (j==1 || j==3 || j==-1||j==-3){
            neighbor = get_neighbor(game.position,j);
            neighbor_of_neighbor = get_neighbor(neighbor,j);
            if ((world_get_sort(game.w , neighbor_of_neighbor ) == NO_SORT) && (world_get_sort(game.w , neighbor ) == PAWN)){
                ajout_position( ss , neighbor_of_neighbor);
            }
            }
        else
            neighbor = get_neighbor(game.position,j);
            neighbor_of_neighbor = get_neighbor(neighbor,j);
            if ((world_get_sort(game.w , neighbor_of_neighbor ) == NO_SORT) && (world_get_sort(game.w , neighbor ) == PAWN)){
                ajout_position( ss , neighbor_of_neighbor);
            }
        }
    }
 
}

/* Fonction qui retourne l'ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) */
void saut_multiple(struct game_t game , struct ensemble* sm  ){
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        while (place_visited ( sm, game.position) == 0){
            saut_simple( game, sm);
            
                game.position = get_neighbor(game.position , j);
                ajout_position(sm, game.position);
        }
    }
    
}

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
void mvts_disponibles (struct game_t game, struct ensemble* md) 
{  
    positions_init(md,game.seed);
    deplacements_simple( game , md );
    saut_multiple( game , md );
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
