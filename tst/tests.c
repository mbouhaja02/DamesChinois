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
#include "prison.h"


/*w = world_init();*/
/*init_neighbors(0); // Use seed 0 at the beginning of a game
current_player = get_random_player();
while nobody has won:
  p = choose_random_piece_belonging_to(w, current_player)
  m = choose_random_move_for_piece(w, p)
  move_piece(w, m)
  current_player = next_player(current_player)*/


int main() { 


  struct game_t game = game_initializer();
  time_t t;
/* Intializes random number generator */
  srand(time(&t));
  start(game);
  game.current_player = get_random_player();
  game.victoire  =  choose_random_victory_type();
  game.seed = 0;
  struct ensemble white_list_initial, black_list_initial;
  unsigned int piece=0;
  unsigned int move=0;
  game.position = piece;
  init_neighbors(game.seed);
  white_list(&white_list_initial, game.w);
  black_list(&black_list_initial, game.w);

  for ( unsigned int i = 0 ; i < MAX_TURNS ; i++){
    game.tour = i;
    choose_random_piece_belonging_to(&game);
    move = choose_random_move_for_piece(game);
    move_piece(game, move);
    draw_world_simple(game);
    if (victoire_type(&game, white_list_initial, black_list_initial) == 1){
            printf("le joueur qui a gagner est %d \n", game.current_player);
            printf("\t victoire complexe = %d \n \n", game.victoire);
            return 0;  
    }
    printf("\n prison black [");
    for(unsigned int i =0; i< game.prison->len_black; i++){
      printf(" %d, ", game.prison->cells_black[i].i);
    }
    printf(" ] \n");

    printf("\n prison white [");
    for(unsigned int i =0; i< game.prison->len_white; i++){
      printf(" %d, ", game.prison->cells_white[i].i);
    }
    printf(" ] \n");
    game.current_player = next_player(game.current_player);  
  }

  printf("\tNombre de tours maximal est atteint \n");
  printf("\tVictoire complexe = %d \n \n", game.victoire);
  return 0;

}

    
    
    

