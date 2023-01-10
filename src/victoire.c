#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "set.h"
#include "movements.h"
#include "victoire.h"
#include "game.h"



//Verify a simple win : if the current player moves to an initial position of the other player  

 
int simple_victory(struct game_t* game, struct set wl, struct set bl) {
    struct set depart_autre_joueur ;
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

//Verify a complex victory
//if all the players positions match with initial positions of the other player 


int complex_victory(struct game_t* game , struct set wl , struct set bl){
    struct set positions_joueur ;

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


int victory_type(struct game_t* game , struct set wl , struct set bl){
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