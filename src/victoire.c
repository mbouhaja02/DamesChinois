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

 
int simple_victory(struct game_t* game, struct ensemble wl, struct ensemble bl) {
    struct ensemble depart_autre_joueur ;
    if (game->current_player == 1 ){
        black_list(&depart_autre_joueur, game->w );
        if (common_element(&depart_autre_joueur, &wl) == 1){
            return 1;
        }
    }
    else {
        white_list(&depart_autre_joueur, game->w);
        if (common_element(&depart_autre_joueur, &bl) == 1){
            return 1;
        }
    }
    return 0; 
}

/* cette fonction va vérifier l'égalité de l'ensemble de positions de 
départ de l'autre joueur et les positions actuels de current_player*/


int complex_victory(struct game_t* game , struct ensemble wl , struct ensemble bl){
    struct ensemble positions_joueur ;

    if (game->current_player == 1 ){
        black_list(&positions_joueur, game->w);
        if (equality_of_two_sets(wl,positions_joueur)==1) {
            return 1; 
        }
    }
    else {
        white_list(&positions_joueur, game->w);
        if (equality_of_two_sets(bl,positions_joueur)==1) {
            return 1; 
        }
    }
    return 0 ; 
}

int victory_type(struct game_t* game , struct ensemble wl , struct ensemble bl){
    if (game->victory == SIMPLE_VICTORY){
        return simple_victory(game, wl, bl);
    }

    else{
        return complex_victory(game, wl, bl);
    }
}

enum victory_t choose_random_victory_type(){
    time_t t;
    srand(time(&t));
    enum victory_t r = rand()%2;
    return r;
}