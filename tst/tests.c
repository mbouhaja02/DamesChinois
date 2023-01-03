#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>
#include <math.h>

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


int main(int argc, char* argv[]) { 
  struct game_t game = game_initializer();
  time_t t;
/* Intializes random number generator */
  srand(time(&t));
  start(game);

  unsigned int victory = 0;
  int turns = MAX_TURNS;
  extern char *optarg;
  int opt = 4;
  while((opt = getopt(argc, argv, "sm:t:h")) != -1){
    switch (opt)
    {
    case 's':
      if(optarg != NULL){
        srand(atoi(optarg));
      }
      
      break;
    case 'm':
      if(optarg != NULL){
        turns = atoi(optarg);
      }
      
      break;
    case 't':
      if(optarg[0] == 'c'){
        victory = 1;
      }      
      break;
    case 'h':
      printf("usage: ./project [-h help] [-s an optional parametre to initialize the RNG]\n \t \t [-m an optional parametre for MAX_TURNS] \n \t \t [-t an optional parametre to set the victory type \n]");
      return 0;
      break;
    
    default:
      break;
    }
  }

  game.victoire = victory;
  game.current_player = get_random_player();
  game.seed = 0;
  struct ensemble white_list_initial, black_list_initial;
  unsigned int piece=0;
  unsigned int move=0;
  game.position = piece;
  init_neighbors(game.seed);
  white_list(&white_list_initial, game.w);
  black_list(&black_list_initial, game.w);
  choose_random_relation(&game);
  for (int i = 0 ; i < turns; i++){
    game.tour = i;
    if (game.tour == sqrt(MAX_TURNS)){
      choose_random_relation(&game);
    }
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

    
    
    

