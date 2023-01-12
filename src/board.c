#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#include "world.h"
#include "set.h"
#include "movements.h"
#include "board.h"
#include "game.h"




//This function initializes the board with pawns  
struct world_t* start(struct game_t game){
    srand(time(NULL));
    if(game.seed == 0){
        for(int i = 0; i< HEIGHT; i++){
            int nbr = WIDTH * i;
            int nbr2 = WIDTH * i + WIDTH - 1;
            int r = rand()%3 + 1;
            world_set_sort( game.w, nbr, r);
            world_set(game.w, nbr, 1);
            world_set_sort( game.w, nbr2, r);
            world_set(game.w, nbr2, 2);

        }
    }


    return game.w;

}

//This function helps draw the world to visualize its current state and position of pawns
void draw_world(struct game_t game){

    if(game.current_player == WHITE){
        printf("\n\t|| Le tour des WHITE ♙ ||\n \n");
    }
    else{
        printf("\n\t|| Le tour des BLACk ♟ ||\n \n");
    }

    if (game.seed == 0){
        printf("\t|| Le type de relation est SIMPLE ||\n\n");
    }
    else if(game.seed == 1){
        printf("\t|| Le type de relation est DIAGONAL ||\n\n");
    }
    else if(game.seed == 2){
        printf("\t|| Le type de relation est TRIANGULAIRE ||\n\n");
    }
    else{
        printf("\t|| Le type de relation est HEXAGONAL || \n\n");
    }




    printf("T%d", game.tour);
    for (int q = 'A'; q <'A'+WIDTH; q++){
        printf("\t    %c", q);
    }

    printf("\n \n");

    for(int i = 0; i < HEIGHT; i++){
        printf("0%d\t ", i);
        for(int j = 0; j < WIDTH; j++){
            
            int nbr = i * WIDTH + j;
            if (world_get_sort( game.w, nbr) == 0 || world_get(game.w,nbr) == 0){
                printf("  . \t");
            }

            if (world_get_sort( game.w, nbr) == 1 && world_get(game.w, nbr) == 1){
               printf("  ♟\t");
            }
                
            if (world_get_sort(game.w, nbr) == 1 && world_get(game.w, nbr) == 2){
                printf("  ♙\t");
                }
            if (world_get_sort(game.w, nbr) == 2 && world_get(game.w,nbr) == 1){
                printf("  ♜\t");

            }
            if (world_get_sort(game.w, nbr) == 3 && world_get(game.w,nbr) == 1){
                printf("  ♝\t");
            }
            if (world_get_sort(game.w, nbr) == 2 && world_get(game.w,nbr) == 2){
                printf("  ♖\t");
            }
            if (world_get_sort(game.w, nbr) == 3 && world_get(game.w,nbr) == 2){
                printf("  ♗\t");
            }
                
        }
        printf("\n");
            
    }
    printf("\n \n");
}


//draws the board we are playing on
void draw_rack(struct game_t game){

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


