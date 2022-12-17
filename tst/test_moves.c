#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "geometry.h"
#include "world.h"
#include "neighbors.h"
#include "ensemble.h"
#include "movements.h"
#include "board.h"
#include "victoire.h"
#include "game.h"


int main(){
    time_t t;
    srand(time(&t));
    struct game_t game ;
    unsigned int move ; 
    game = game_initializer();
    start(game);
    choose_random_piece_belonging_to(&game);

    struct ensemble ds,sm; 
    draw_world(game);
    deplacements_simple(game, &ds);
    saut_multiple(game ,&sm );
    move = choose_random_move_for_piece(game);
    move_piece(&game, move);
    draw_world(game);
    choose_random_piece_belonging_to(&game);
    return 0;
}