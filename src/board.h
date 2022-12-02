#ifdef __BOARD_H__
#define __BOARD_H__

#ifdef NBR_PAWN
    #define NBR_PAWN 12
#endif


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"

struct world_t* debut(struct world_t* w);
void draw_world(struct world_t* w);




#endif // __BOARD_H__