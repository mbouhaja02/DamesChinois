#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"

struct mouvement_dispo;
int mvt_disponible_en_direction(struct world_t w; unsigned char idx, enum dir_t d){
    unsigned int n = get_neighbor(idx,j);
    if (w.positions[n][1]==1);{
        return 0;
    }
    return 1; 
}

struct ensemble mvts_disponibles (struct world_t w; unsigned char idx; struct ensemble* md ) 
{   int* i = 0; 
    for (enum dir_t j = SEAST; j < NWEST ;j++)
    {   
        if (mvt_disponible_en_direction(w,idx,j)==1){
            mvts_dispo.positions[j+4]=get_neighbor(idx,j+4);
        else
            if ()
            mvts_disponibles(w,get_neighbor(idx,j+4));
        
        }
    }
       

}