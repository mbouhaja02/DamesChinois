#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"


/* fonction qui prend l'ensemble des positions initiales de l'autre
 joueur et cherche si le prochain tour ( s'il en reste )du joueur 
 l'emmenera vers une des positions de départ dans l'ensemble */
int Victoire_Simple(struct world_t w , unsigned int place , enum color_t joueur , unsigned int tours ) {
    struct ensemble* depart_autre_joueur ;
    if (joueur == "BLACK" ){
        depart_autre_joueur = white_list (depart_autre_joueur, w );
    else 
        depart_autre_joueur = black_list ( depart_autre_joueur, w);
    }
    if ((place_visited(depart_autre_joueur , place ) && (tours < MAX_TURNS)){
        return 1;
    }
    return 0; 
}

/* cette fonction va prendre le monde dans l'état de tour t et le
 world initiale et vérifie le joueur dans l'instant t à tous ses 
 pions sur les positions de départs de l'autre joueur */

int Victoire_complexe(struct world_t* w , unsigned int tours , enum color_t joueur , struct world_t* wt){
    struct ensemble* depart_autre_joueur ;
    struct ensemble* positions_joueur ;

    if (joueur == "BLACK" ){
        depart_autre_joueur = white_list (depart_autre_joueur, w );
        positions_joueur = black_list (positions_joueur, wt);

    else 
        depart_autre_joueur = black_list ( depart_autre_joueur, w);
        positions_joueur = white_list (positions_joueur, wt);
    }
    if depart_autre_joueur = positions_joueur {
        return 1 ; 
    }
    return 0 ; 
}