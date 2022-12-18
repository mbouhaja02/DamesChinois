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
    struct game_t game = game_initializer();
    time_t t;
    srand(time(&t));
    start(game);
    game.current_player = get_random_player();
    struct ensemble white_list_initial, black_list_initial;
    game.victoire = 0;
    game.seed = 0;
    unsigned int move;
    init_neighbors(game.seed);
    white_list(&white_list_initial, game.w);
    black_list(&black_list_initial, game.w);
    draw_world(game);


    for ( unsigned int i = 0 ; i < MAX_TURNS ; i++){
        game.tour = i;
        choose_random_piece_belonging_to(&game);
        move = choose_random_move_for_piece(game);
        move_piece(&game, move);
        draw_world(game);
        if (victoire_type(&game, white_list_initial, black_list_initial) == 1){
            printf("le joueur qui a gagner est %d \n", game.current_player);
            return 0;  
        }
        game.current_player = next_player(game.current_player);  
    }

    printf("Nombre de tours maximal est atteint \n");
    return 0;
}