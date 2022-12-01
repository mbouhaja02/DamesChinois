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
void begin(); 

int main() { 
    struct world_t* w = world_init();
    unsigned int seed = 0;
    init_neighbors(0);
    enum color_t current_player = get_random_player();
    for(unsigned int j = 0 ; j < MAX_TURNS; j++){
      unsigned int p = choose_random_piece_belonging_to(w, current_player);
      unsigned int m = choose_random_move_for_piece(w, p);
      w = move_piece(w, m, p, current_player);
      if (Victoire_Simple(w, p, current_player, j) == 1)
          return "le jeu est terminé";
      current_player = next_player(current_player);
    }
}

    
    
    

