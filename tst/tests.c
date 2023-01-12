#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>
#include <math.h>

#include "geometry.h"
#include "world.h"
#include "neighbors.h"
#include "set.h"
#include "movements.h"
#include "board.h"
#include "victoire.h"
#include "game.h"
#include "prison.h"





int main(int argc, char* argv[]) { 
  struct game_t game = game_initializer();
  //choose_random_relation(&game);

  game.seed = 3;
/* Intializes random number generator */
  start(game);
  enum victory_t victory = SIMPLE_VICTORY;
  int turns = MAX_TURNS;
  extern char *optarg;
  int opt = 0;
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
        victory = COMPLEX_VICTORY;
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

  game.victory = victory;
  game.current_player = get_random_player();
  struct set white_list_initial, black_list_initial;
  unsigned int piece=0;
  unsigned int move=0;
  game.position = piece;
  init_neighbors(game.seed);
  white_list(&white_list_initial, game.w);
  black_list(&black_list_initial, game.w);
  for (int i = 0 ; i < turns; i++){
    game.turn = i;
    if (game.turn == floor(sqrt(MAX_TURNS))){
      //choose_next_random_relation(&game);
    }
    choose_random_piece_belonging_to(&game);
    move = choose_random_move_for_piece(game);
    move_piece(game, move);
    draw_world(game);
    if (victory_type(&game, white_list_initial, black_list_initial) == 1){
            printf("le joueur qui a gagner est %d \n", game.current_player);
            printf("\t victoire complexe = %d \n \n", game.victory);
            return 0;  
    }
    printf("\n Prison : Black [");
    for(unsigned int i =0; i< game.jail->len_black; i++){
      printf(" %d, ", game.jail->cells_black[i].i);
    }
    printf(" ] \n");

    printf("\n \t  White [");

    for(unsigned int i =0; i< game.jail->len_white; i++){
      printf(" %d, ", game.jail->cells_white[i].i);
    }
    printf(" ] \n");
    game.current_player = next_player(game.current_player);  
  }

  printf("\tNombre de tours maximal est atteint \n");
  printf("\tVictoire complexe = %d \n \n", game.victory);
  return 0;

}

    
    
    

