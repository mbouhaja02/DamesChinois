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
  struct world_t* wt = w ; 
  enum color_t current_player = get_random_player();
  unsigned int place ; 
  unsigned int move ; 
  for ( int i = 0 ; i < 2*MAX_TURNS ; i++){
    place = choose_random_piece_belonging_to(wt , current_player);
    move = choose_random_move_for_piece(wt , place);
    move_piece(wt , move , place , current_player);
    if ((Victoire_Simple(w , move , current_player , i/2 )==1)||(Victoire_complexe(w , i/2 , current_player, wt)==1)){
      return 1;
    }
    current_player = next_player(current_player);
  }
  
  return 0;
}

    
    
    

