#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "victoire.h"
#include "game.h"



/* fonction qui prend l'ensemble des positions initiales de l'autre
 joueur et cherche si le prochain tour ( s'il en reste )du joueur 
 l'emmenera vers une des positions de départ dans l'ensemble */

 
int Victoire_Simple(struct game_t* game, struct ensemble wl, struct ensemble bl) {
    struct ensemble depart_autre_joueur ;
    positions_init(&depart_autre_joueur);
    if (game->current_player == 1 ){
        black_list(&depart_autre_joueur, game->w );
        if (element_commun(&depart_autre_joueur, &wl) == 1){
            return 1;
        }
    }
    else {
        white_list(&depart_autre_joueur, game->w);
        if (element_commun(&depart_autre_joueur, &bl) == 1){
            return 1;
        }
    }
    return 0; 
}

/* cette fonction va vérifier l'égalité de l'ensemble de positions de 
départ de l'autre joueur et les positions actuels de current_player*/


int Victoire_complexe(struct game_t* game , struct ensemble wl , struct ensemble bl){
    struct ensemble positions_joueur ;
    positions_init(&positions_joueur);

    if (game->current_player == 1 ){
        black_list(&positions_joueur, game->w);
        if (egalite_de_deux_ensembles(wl,positions_joueur)==1) {
            return 1; 
        }
    }
    else {
        white_list(&positions_joueur, game->w);
        if (egalite_de_deux_ensembles(bl,positions_joueur)==1) {
            return 1; 
        }
    }
    return 0 ; 
}

int victoire_type(struct game_t* game , struct ensemble wl , struct ensemble bl){
    printf("%d \n", game->victoire);
    if (game->victoire == 0){
        printf("# \n");
        return Victoire_Simple(game, wl, bl);
    }

    else{
        return Victoire_complexe(game, wl, bl);
    }
}

enum victoire_t choose_random_victory_type(){
    time_t t;
    srand(time(&t));
    enum victoire_t r = rand()%2;
    return r;
}