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
    for(int i =0 ; i<HEIGHT; i++){
        int nbr = HEIGHT*i;
        int nbr2 = HEIGHT*i + WIDTH-1;
        world_set_sort( w, nbr, 1);
        world_set(w, nbr, 1);
        world_set_sort( w, nbr2, 2);
        world_set(w, nbr2, 2);
    }
    return w;

}

void begin(){

    struct world_t* w = debut();

    for (int h = 0; h < HEIGHT; h++){
        printf("\t %d", h);
    }
    for(int i =0; i < 10; i++){
        printf("%d\t", i+1);
        for(int j = 0; j < 10; j++){
            
            int nbr = i * HEIGHT + j;
            if (world_get_sort( w, nbr) == 0){
                printf(" N\t");
            }
            if (world_get_sort( w, nbr) == 1){
                if (world_get(w, nbr) == 1){
                    printf(" B\t");
                }
                if (world_get(w, nbr) == 2){
                    printf(" W\t");
                }
                
            }
            
        }
        printf("\n");
    }
    
}

