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

  begin();
    struct world_t* w = world_init();

    for (int i = 0; i < 10; i++){
      enum color_t c = get_random_player();
      enum color_t b = next_player(c);
      unsigned int p = choose_random_piece_belonging_to(w, c);
      unsigned int m = choose_random_move_for_piece(w, p);
      unsigned int p2 = choose_random_piece_belonging_to(w, b);
      printf("%d de couleur %d et le move %d-- %d de couleur %d \n", (int)c, p, m, (int)b, p2);
    }
    enum color_t d = world_get(w, 9);
    printf("\n %d \n", (int)d);

    enum color_t d1 = world_get(w, 10);
    printf("\n %d \n", (int)d1);

    enum color_t d2 = world_get(w, 19);
    printf("\n %d \n", (int)d2);

    
  return 0;
}

    
    
    

