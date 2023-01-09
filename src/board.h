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





//Une fonction qui retourne un wolrd où les positions des pawn pour les deux joueurs sont initiés
struct world_t* start(struct game_t game);

//Une fonction qui trace le monde w
void draw_world(struct game_t game);

void draw_world_simple(struct game_t game);

void draw_grille(struct game_t game);




#endif // __BOARD_H__