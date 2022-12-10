#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "geometry.h"
#include "world.h"
#include "neighbors.h"
#include "ensemble.h"
#include "movements.h"
#include "board.h"
#include "victoire.h"
#include "partie.h"


/*w = world_init();*/
/*init_neighbors(0); // Use seed 0 at the beginning of a game
current_player = get_random_player();
while nobody has won:
  p = choose_random_piece_belonging_to(w, current_player)
  m = choose_random_move_for_piece(w, p)
  move_piece(w, m)
  current_player = next_player(current_player)*/


int main() { 

  srand(time(NULL));
  struct world_t* w = world_init();
  enum color_t current_player = get_random_player();
  enum victoire_t victoire = choose_random_victory_type();
  struct ensemble white_list_initial , black_list_initial;
  unsigned int piece=0;
  unsigned int move=0;
  unsigned int seed = rand () % 2 ; 
  init_neighbors(seed);
  srand(time(NULL));
  draw_world(w);
  debut(w);
  draw_world(w);
  white_list(&white_list_initial, w);
  black_list(&black_list_initial, w);
  struct game_t* game;
  


  for ( unsigned int i = 0 ; i < MAX_TURNS ; i++){
    game->current_player = current_player ;
    game->tour = i;
    game->w = w ;
    game->seed = seed ; 
    game->position = piece ;
    game->victoire = victoire ;
    if (victoire_type(game, white_list_initial, black_list_initial) == 0){
      choose_random_piece_belonging_to(game);
      move = choose_random_move_for_piece(game);
      move_piece(game, move);
      current_player = next_player(current_player);
      
      //draw_world(w);    
    }
  }
  printf("la victoire est de %u \n", current_player);
  return 0;

}

    
    
    

