#ifndef __DISTANCE_H_
#define __DISTANCE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "geometry.h"
#include "world.h"
#include "neighbors.h"
#include "ensemble.h"
#include "movements.h"

#define MIN(i, j) (((i) < (j)) ? (i) : (j))

unsigned int distance(struct game_t game, unsigned int a , unsigned int b);
unsigned int closest_to_ensemble(unsigned int a, struct ensemble ensemble );
unsigned int closest_in_ensemble1_to_ensemble2(struct ensemble ensemble1, struct ensemble ensemble2);
unsigned int closest_movement_to_other_player(struct game_t game);

#endif