#ifndef __BOARD_H__
#define __BOARD_H__

#ifndef NBR_PAWN
    #define NBR_PAWN 12
#endif


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "board.h"
#include "game.h"





//This function initializes the board with pawns  
struct world_t* start(struct game_t game);

//This function helps draw the world to visualize its current state and position of pawns
void draw_world(struct game_t game);

//draws the board we are playing on
void draw_rack(struct game_t game);




#endif // __BOARD_H__