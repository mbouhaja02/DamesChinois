#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "wolrd.h"


typedef struct ensemble

struct ensemble{
    unsigned int taille;
    unsigned int positions[taille];
    
} ensemble;



struct positions_init{
    struct ensemble={NP};
}

struct positions_white{
    struct ensemble={NW};
}

struct positions_black{
    struct ensemble={NB};
}

struct mouvement_dispo{
    struct ensemble={MV};
}


