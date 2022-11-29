#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"


/* Fonction qui retourne l'ensemble des déplacements simple possible */
struct ensemble* deplacements_simple(struct world_t* w , unsigned char idx , struct ensemble* ds){
    unsigned int gn;
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        gn = get_neighbor(idx , j);
        if (world_get_sort(w , gn ) == 0){
            ajout_position( ds , gn);
        }
    }
    return ds;
}
/* Fonction qui retourne l'ensemble des sauts simples */
struct ensemble* saut_simple(struct world_t* w , unsigned char idx , struct ensemble* ss){
    unsigned int gn;
    unsigned int gnn; 
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        gn = get_neighbor(idx,j);
        gnn = get_neighbor(gn,j);
        if ((world_get_sort(w , gn ) == 1) && (world_get_sort(w , gnn ) == 0)){
            ajout_position( ss , gnn);
        }
    }
    return ss;
}

/* Fonction qui retourne l'ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) */
struct ensemble* saut_multiple(struct world_t* w , unsigned int idx , struct ensemble* sm){
    for (enum dir_t j = SEAST; j < NWEST ;j++){
        while (place_visited ( sm, idx ) == 0){
            saut_simple(w,idx,sm);
            idx = get_neighbor(idx , j);
        }
    }
    return sm;
}

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
struct ensemble* mvts_disponibles (struct world_t* w, unsigned char idx, struct ensemble* md ) 
{  
    struct ensemble* sm;
    md = deplacements_simple( w , idx , md );
    sm = saut_multiple( w , idx , sm);
    concatener_ensembles ( md , sm );
    return md;
}