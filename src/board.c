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
#include "prison.h"



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

void draw_world(struct game_t game){
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



void draw_world_simple(struct game_t game){
    for(int i =0; i < WIDTH+1; i++){
        printf(" _______");
    }
    printf("\n");
    printf("|   ");
    for (int q = 'A'; q <'A'+WIDTH; q++){
        printf("\t    %c ", q);
    }
    printf("\t|");
    printf("\n");
    for(int i =0; i < WIDTH+1; i++){
        printf(" _______");
    }
    printf("\n| \n");


    for(int i = 0; i < HEIGHT; i++){
        for(int h = 0; h < 3; h++){
            if(h != 1){
                printf("|   \t ");
            }
            else if( h == 1){
                printf("|0%d\t ", i);
            }
            for(int j = 0; j < WIDTH; j++){
            
                int nbr = i * WIDTH + j;
                if (world_get_sort( game.w, nbr) == 0 || world_get(game.w,nbr) == 0){
                    switch (h)
                    {
                    case 0:
                        printf("      \t");
                        break;
                    case 1:
                        printf("      \t");
                        break;
                    case 2:
                        printf("   .  \t");
                        break;
                    
                    default:
                        break;
                    }
                }
                if (world_get_sort( game.w, nbr) == 1 && world_get(game.w, nbr) == 1){
                    switch (h)
                    {
                    case 0:
                        printf("      \t");
                        break;
                    case 1:
                        printf(" _____\t");
                        break;
                    case 2:
                        printf(" |_b_|\t");
                        break;
                    
                    default:
                        break;
                    }
                }
                if (world_get_sort(game.w, nbr) == 2 && world_get(game.w,nbr) == 1){
                    switch (h)
                    {
                    case 0:
                        printf(" |---|\t");
                        break;
                    case 1:
                        printf(" |||||\t");
                        break;
                    case 2:
                        printf(" |_b_|\t");
                        break;
                    
                    default:
                        break;
                    }
                }
                if (world_get_sort(game.w, nbr) == 3 && world_get(game.w,nbr) == 1){
                    switch (h)
                    {
                    case 0:
                        printf("   _  \t");
                        break;
                    case 1:
                        printf("  | | \t");
                        break;
                    case 2:
                        printf(" |_b_|\t");
                        break;
                    
                    default:
                        break;
                    }
                }
                if (world_get_sort( game.w, nbr) == 1 && world_get(game.w, nbr) == 2){
                    switch (h)
                    {
                    case 0:
                        printf("      \t");
                        break;
                    case 1:
                        printf(" _____\t");
                        break;
                    case 2:
                        printf(" |_w_|\t");
                        break;
                    
                    default:
                        break;
                    }
                }
                if (world_get_sort(game.w, nbr) == 2 && world_get(game.w,nbr) == 2){
                    switch (h)
                    {
                    case 0:
                        printf(" |---|\t");
                        break;
                    case 1:
                        printf(" |||||\t");
                        break;
                    case 2:
                        printf(" |_w_|\t");
                        break;
                    
                    default:
                        break;
                    }
                }
                if (world_get_sort(game.w, nbr) == 3 && world_get(game.w,nbr) == 2){
                    switch (h)
                    {
                    case 0:
                        printf("   _  \t");
                        break;
                    case 1:
                        printf("  | | \t");
                        break;
                    case 2:
                        printf(" |_w_|\t");
                        break;
                    
                    default:
                        break;
                    }
                }
            }
            printf("|");
            printf("\n");
        }
        printf("|");
        printf("\n");
    }

    for(int i =0; i < WIDTH+1; i++){
        printf(" _______");
    }

    printf("\n ");
    printf("\t   Tour numéro %d (T%d)", game.tour+1, game.tour+1);
    printf("\n");
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


