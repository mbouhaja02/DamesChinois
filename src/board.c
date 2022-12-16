#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "board.h"
#include "game.h"



struct world_t* debut(struct game_t game){

    if (game.seed == 0){
        for(int i =0 ; i<HEIGHT; i++){
            int nbr = WIDTH *i;
            int nbr2 = WIDTH *i + WIDTH-1;
            world_set_sort( game.w, nbr, 1);
            world_set(game.w, nbr, 1);
            world_set_sort( game.w, nbr2, 2);
            world_set(game.w, nbr2, 2);
        }
    }

    return game.w;

}

void draw_world(struct world_t* w){

    for (int h = 'A'; h <'A'+WIDTH; h++){
        printf("\t  %c", h);
    }

    printf("\n \n");

    for(int i = 0; i < HEIGHT; i++){
        printf("0%d\t ", i);
        for(int j = 0; j < WIDTH; j++){
            
            int nbr = i * WIDTH + j;
            if (world_get_sort( w, nbr) == 0 && world_get(w,nbr) == 0){
                printf("  . \t");
            }

            if (world_get_sort( w, nbr) == 1 && world_get(w, nbr) == 1){
               printf(" |B|\t");
            }
                
            if (world_get(w, nbr) == 2 && world_get(w, nbr) == 2){
                    printf(" |W|\t");
                }
                
        }
        printf("\n");
            
    }

    printf("\n \n");
}


void draw_grille(struct game_t game){

    if (game.seed == 0){
        for(int i = 0; i < 5; i++){
            for (int j = 0; j < 3 ; j++){
                while (j < 3){
                    printf("\t.\t");
                    j++;
                }
                printf("\n");
            }
        }
    }

}



