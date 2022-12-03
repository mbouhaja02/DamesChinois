#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"





/* Fonction qui retourne l'ensemble des déplacements simple possible */
void deplacements_simple(struct world_t* w , unsigned int idx , struct ensemble* ds ){
    unsigned int gn;
    positions_init(ds);
    for (enum dir_t j = SEAST; j < NWEST+1 ;j++){
        gn = get_neighbor(idx , j);
        printf("%u\n", gn);
        enum sort_t b = world_get_sort(w, gn);

        if ( b == NO_SORT){
            ajout_position( ds , gn);
            
        }
    }
    printf("#\n");
}
/* Fonction qui retourne l'ensemble des sauts simples */
void saut_simple(struct world_t* w , unsigned int idx , struct ensemble* ss ){
    unsigned int gn;
    unsigned int gnn; 
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        gn = get_neighbor(idx,j);
        gnn = get_neighbor(gn,j);
        if ((world_get_sort(w , gn ) == 1) && (world_get_sort(w , gnn ) == 0)){
            ajout_position( ss , gnn);
        }
    }
 
}

/* Fonction qui retourne l'ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) */
void saut_multiple(struct world_t* w , unsigned int idx , struct ensemble* sm ){
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        while (place_visited ( sm, idx ) == 0){
            saut_simple(w,idx,sm);
            idx = get_neighbor(idx , j);
            ajout_position(sm, idx);
        }
    }
    
}

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
struct ensemble* mvts_disponibles (struct world_t* w, unsigned int idx, struct ensemble* md ) 
{  
    
    deplacements_simple( w , idx , md );
    saut_multiple( w , idx , md);
    
    return md;
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
        while(world_get_sort(w, idx2) == 0){
            ajout_position(&ens, idx2);
            idx2 = get_neighbor(idx2, tab_dir[i]);
        }
    }
    return ens;
}