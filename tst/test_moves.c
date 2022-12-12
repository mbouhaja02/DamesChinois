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
#include "partie.h"


int main(){
    time_t t;
    srand(time(&t));
    struct game_t game ;
    unsigned int move ; 
    game = game_initializer();
    debut(game.w);
    printf("position before %d\n", game.position);
    choose_random_piece_belonging_to(&game);
    for(int i = 0; i < MAX_NEIGHBORS; i++){
        printf("%d \t", neighbors[game.position].n[i].i);
    }
    printf("position after %d\n", game.position);
    printf("place = %d\n", game.position);
    struct ensemble ds,sm; 
    draw_world(game.w);
    deplacements_simple(game, &ds);
    printf("#\n");
    saut_multiple(game ,&sm );
    move = choose_random_move_for_piece(game);
    move_piece(&game, move);
    draw_world(game.w);
    choose_random_piece_belonging_to(&game);
    for(int i = 0; i < MAX_NEIGHBORS; i++){
        printf("%d \t", neighbors[game.position].n[i].i);
        printf("%d \t", neighbors[game.position].n[i].d);
    }
    return 0;
}