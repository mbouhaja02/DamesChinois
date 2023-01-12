#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "world.h"
#include "set.h"
#include "movements.h"
#include "victoire.h"
#include "game.h"
#include "prison.h"

//this structure helps organize the configuration of a game and put it in one argument
struct game_t {
    enum color_t current_player;
    unsigned int turn;
    struct world_t* w;
    struct jail_t* jail;
    unsigned int seed;
    unsigned int position;
    enum victory_t victory;

};

//chooses a random color designed to a player
enum color_t get_random_player();

//helps switch players in the game
enum color_t next_player(enum color_t current_player);

//Choose out of the positions of the current player
void choose_random_piece_belonging_to(struct game_t* game);

//Choose out of the list of available moves
unsigned int choose_random_move_for_piece(struct game_t game);

//make the move in the world by changing the initial position in the game to the
//destination and empties the initial squarevoid move_piece(struct game_t game, unsigned int dst);
void move_piece(struct game_t game, unsigned int dst);

//Initializes game
struct game_t game_initializer();

//chooses the relation mode randomly
void choose_random_relation(struct game_t *game);

//chooses the next relation mode randomly
void choose_next_random_relation(struct game_t* game);




#endif // __GAME_H__