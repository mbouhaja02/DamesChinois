#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/geometry.h"
#include "../src/world.h"
#include "../src/neighbors.h"
#include "../src/geometry.c"
#include "../src/world.c"
#include "../src/neighbors.c"

/*w = world_init();
init_neighbors(0); // Use seed 0 at the beginning of a game
current_player = get_random_player();
while nobody has won:
  p = choose_random_piece_belonging_to(w, current_player)
  m = choose_random_move_for_piece(w, p)
  move_piece(w, m)
  current_player = next_player(current_player)*/

int main() { 
    
    place_to_string (2,1); //geometry.c
    dir_to_string(3);
    struct world_t* w;
    w=world_init();
    world_get (w , 3);
    world_set(w,3,1);
    for (int i=0 ; i<WORLD_SIZE ; i++ ) {
      printf("{%d , %d }\n" , w->positions[i][1],w->positions[i][2]);
      
    }
}
