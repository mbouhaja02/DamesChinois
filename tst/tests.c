#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/geometry.h"
#include "../src/world.h"
#include "../src/neighbors.h"
#include "../src/ensemble.h"
#include "../src/movements.h"
#include "../src/board.h"
#include "../src/victoire.h"
#include "../src/partie.h"


/*w = world_init();*/
/*init_neighbors(0); // Use seed 0 at the beginning of a game
current_player = get_random_player();
while nobody has won:
  p = choose_random_piece_belonging_to(w, current_player)
  m = choose_random_move_for_piece(w, p)
  move_piece(w, m)
  current_player = next_player(current_player)*/


int main() { 

  struct world_t* w = world_init();
  enum color_t current_player = get_random_player();
  init_neighbors(0);
  unsigned int place;
  unsigned int move;
  debut(w);
  
  
  
  for ( int i = 0 ; i < 2*MAX_TURNS ; i++){
    place = choose_random_piece_belonging_to(w , current_player);
    move = choose_random_move_for_piece(w , place);
    printf("3\n");
    move_piece(w , move , place , current_player);
    printf("4\n");
    current_player = next_player(current_player);
    draw_world(w);
  }
  
  
  return 0;
}

    
    
    

