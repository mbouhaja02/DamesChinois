#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FALSE (1==0)
#define TRUE  (1==1)

#include "geometry.h"
#include "neighbors.h"
#include "wolrd.h"
BOOL mvt_disponible_en_direction(struct world_t w; unsigned char idx, enum dir_t d){
    unsigned int n = get_neighbor(idx,j);
    if (w.positions[n][1]==1);{
        return TRUE;
    }
    return FALSE ; 
}

struct ensemble mvts_disponibles (struct world_t w; unsigned char idx)
{}
    struct neighbors_t mvts_dispo;  
    for (enum dir_t j = SEAST; j < NWEST ;j++)
    {
        if (mvt_disponible_en_direction(w,idx,j)){
            mvts_dispo.positions[j]=get_neighbor(idx,j);
        else
            mvts_disponibles(w,get_neighbor(idx,j));
        
        }
    }
       

}