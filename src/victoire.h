#ifndef __VICTOIRE_H__
#define __VICTOIRE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "victoire.h"
#include "game.h"

#define MAX_TURNS 10
#define VICTORY_TYPES 2

struct game_t;

struct ensemble;

enum victory_t {
    SIMPLE_VICTORY  = 0,
    COMPLEX_VICTORY = 1,
};

int simple_victory(struct game_t* game, struct ensemble wl, struct ensemble bl);

int complex_victory(struct game_t* game , struct ensemble wl , struct ensemble bl);

int victory_type(struct game_t* game , struct ensemble wl , struct ensemble bl);

enum victory_t choose_random_victory_type();

#endif