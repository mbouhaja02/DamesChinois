#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "board.h"



struct world_t* debut(){
    struct world_t* w = world_init();
    for(int i =0 ; i<10; i++){
        int nbr = HEIGHT*i;
        int nbr2 = HEIGHT*i + WIDTH-1;
        world_set_sort( w, nbr, 1);
        world_set(w, nbr, 1);
        world_set_sort( w, nbr2, 2);
        world_set(w, nbr2, 2);
    }
    return w;

}
rand() % (upper – lower + 1)) + lower 
int choose_random_piece_belonging_to(w, current_player)

choose_random_move_for_piece(w, p)
struct world_t move_piece(w, m)

void begin(){

    struct world_t* w = debut();

    for (int h = 0; h < WIDTH; h++){
        printf("\t 0%d", h);
        
    }
    printf("\n \n");
    for(int i =0; i < HEIGHT; i++){
        printf("0%d\t ", i);
        for(int j = 0; j < WIDTH; j++){
            
            int nbr = i * HEIGHT + j;
            if (world_get_sort( w, nbr) == 0){
                printf(" .\t");
            }
            if (world_get_sort( w, nbr) == 1 && world_get(w, nbr) == 1){
               printf(" B\t");
            }
                
            if (world_get(w, nbr) == 2 && world_get(w, nbr) == 2){
                    printf(" W\t");
                }
                
            }
        printf("\n");
            
        }
        
    }
    


