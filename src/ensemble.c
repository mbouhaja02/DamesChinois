#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "wolrd.h"


struct ensemble{
    int nbr_pawn_player;
    unsigned int positions_init[nbr_pawn_player * 2] = {0};
    unsigned int positionw_black[nbr_pawn_player] = {0};
    unsigned int positions_white[nbr_pawn_player] = {0};
} ensemble;

typedef struct ensemble
