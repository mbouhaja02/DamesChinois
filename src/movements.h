#ifndef __MOVEMENTS_H__
#define __MOVEMENTS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "set.h"
#include "movements.h"
#include "game.h"
#include "prison.h"



//Stocks a set of available simple moves for the current position
void simple_moves( struct game_t game, struct set* sm);

//Stocks a set of available simple moves captured for the current position
void simple_moves_capture( struct game_t game, struct set* smc);



//Stocks a set of available simple jumps for the current position
void simple_jumps(struct game_t game , struct set* sj);

//Stocks a set of available simple jumps captured for the current position
void simple_jumps_capture(struct game_t game , struct set* sjc);



//Stocks a set of available multiple jumps for the current position
void multiple_jumps(struct game_t game , struct set* mj);

//Stocks a set of available multiple jumps captured for the current position
void multiple_jumps_capture(struct game_t game , struct set* mjc  );



//Stocks a set of available moves for the current position if its an elephant
void semi_diagonal_jumps(struct game_t game, struct set* sdj);

//Stocks a set of available capture jumps for the current position if its an elephant
void semi_diagonal_jumps_capture(struct game_t game, struct set* sdjc);



//Stocks a set of available moves for the current position if its a tower
void cardinal_translations(struct game_t game, struct set* ct);

//Stocks a set of available capture jumps for the current position if its a tower
void cardinal_translations_capture(struct game_t game, struct set* ctc);



//Stocks a set of available moves for the current position assembling all the past sets
void available_movements(struct game_t game, struct set* am);

//If a destination of a player pawn meets the other player's pawn it will be captured 
void available_captures(struct game_t game, struct set* ac);


#endif //__MOVEMENTS_H__