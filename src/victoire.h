#ifndef __VICTOIRE_H__
#define __VICTOIRE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "set.h"
#include "movements.h"
#include "victoire.h"
#include "game.h"

#define MAX_TURNS 10
#define VICTORY_TYPES 2

struct game_t;

struct set;

enum victory_t {
    SIMPLE_VICTORY  = 0,
    COMPLEX_VICTORY = 1,
};

//Verify a simple win : if the current player moves to an initial position of the other player  
int simple_victory(struct game_t* game, struct set wl, struct set bl);

//Verify a complex victory
//if all the players positions match with initial positions of the other player 
int complex_victory(struct game_t* game , struct set wl , struct set bl);

int victory_type(struct game_t* game , struct set wl , struct set bl);

enum victory_t choose_random_victory_type();

#endif