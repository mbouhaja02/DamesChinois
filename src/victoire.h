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

enum victoire_t {
    victoire_simple   = 0,
    victoire_complexe = 1,
};

int Victoire_Simple(struct game_t* game, struct ensemble wl, struct ensemble bl);

int Victoire_complexe(struct game_t* game , struct ensemble wl , struct ensemble bl);

int victoire_type(struct game_t* game , struct ensemble wl , struct ensemble bl);

enum victoire_t choose_random_victory_type();

#endif