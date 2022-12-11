#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "victoire.h"
#include "partie.h"



/* fonction qui prend l'ensemble des positions initiales de l'autre
 joueur et cherche si le prochain tour ( s'il en reste )du joueur 
 l'emmenera vers une des positions de départ dans l'ensemble */
struct ensemble;
 
int Victoire_Simple(struct game_t* game) {
    struct ensemble depart_autre_joueur ;
    positions_init(&depart_autre_joueur);
    if (game->current_player == 1 ){
        white_list(&depart_autre_joueur, game->w );
    }
    else {
        black_list ( &depart_autre_joueur, game->w);
    }
    if (place_visited(&depart_autre_joueur, game->position) && (game->tour < MAX_TURNS)){
        return 1;
    }
    return 0; 
}

/* cette fonction va vérifier l'égalité de l'ensemble de positions de 
départ de l'autre joueur et les positions actuels de current_player*/


int Victoire_complexe(struct game_t* game , struct ensemble wl , struct ensemble bl){
    struct ensemble depart_autre_joueur, positions_joueur ;
    positions_init(&depart_autre_joueur);
    positions_init(&positions_joueur);

    if (game->current_player == 1 ){
        black_list(&positions_joueur, game->w);
        depart_autre_joueur = wl;
    }
    else {
        white_list(&positions_joueur, game->w);
        depart_autre_joueur = bl;
    }
    if (egalite_de_deux_ensembles(depart_autre_joueur,positions_joueur)==1 && (game->tour < MAX_TURNS)) {
        return 1 ; 
    }
    return 0 ; 
}

int victoire_type(struct game_t* game , struct ensemble wl , struct ensemble bl){
    if (game->victoire == 0){
        Victoire_Simple(game);
    }

    else  if (game->victoire ==1) {
        Victoire_complexe(game, wl, bl);
    }
    return 0;
}

enum victoire_t choose_random_victory_type(){
    enum victoire_t r = rand()%2;
    return r;
}