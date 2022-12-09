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

  struct world_t* w = world_init();
  enum color_t current_player = get_random_player();
  struct ensemble white_list_initial , black_list_initial;
  init_neighbors(0);
  unsigned int piece=0;
  unsigned int move=0;
  srand(time(NULL));
  draw_world(w);
  debut(w);
  draw_world(w);
  white_list(&white_list_initial, w);
  black_list(&black_list_initial, w);
  for ( unsigned int i = 0 ; i < 2*MAX_TURNS ; i++){
    printf("#\n");
    while (Victoire_Simple(w , piece , current_player, i)==0 && Victoire_complexe(w , i, current_player, white_list_initial, black_list_initial)==0){
      
      piece = choose_random_piece_belonging_to(w, current_player);
      printf("piece = %d \n" , piece );
      move = choose_random_move_for_piece(w, piece , current_player );
      printf("move = %d \n" , move);
      move_piece(w, move, piece);
      printf("mp\n");
      current_player = next_player(current_player);
      printf("cp\n");
      draw_world(w);
    
  }
  printf("Victoire de %d\n", current_player);
  return 0;
}
}

    
    
    

