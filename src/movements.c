#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"





/* Fonction qui retourne l'ensemble des déplacements simple possible */
void deplacements_simple(struct world_t* w , unsigned int idx , struct ensemble* ds){
    unsigned int gn;
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        gn = get_neighbor(idx , j);
        if (world_get_sort(w , gn ) == 0){
            ajout_position( ds , gn);
        }
    }
  
}
/* Fonction qui retourne l'ensemble des sauts simples */
void saut_simple(struct world_t* w , unsigned int idx , struct ensemble* ss){
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
void saut_multiple(struct world_t* w , unsigned int idx , struct ensemble* sm){
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        while (place_visited ( sm, idx ) == 0){
            saut_simple(w,idx,sm);
            idx = get_neighbor(idx , j);
        }
    }
    
}

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
struct ensemble* mvts_disponibles (struct world_t* w, unsigned int idx, struct ensemble* md ) 
{  
    struct ensemble sm;
    deplacements_simple( w , idx , md );
    saut_multiple( w , idx , &sm);
    concatener_ensembles ( md , &sm );
    return md;
}