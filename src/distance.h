#ifndef __DISTANCE_H_
#define __DISTANCE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "geometry.h"
#include "world.h"
#include "neighbors.h"
#include "set.h"
#include "movements.h"

#define MIN(i, j) (((i) < (j)) ? (i) : (j))

unsigned int distance(struct game_t game, unsigned int a , unsigned int b);


unsigned int closest_to_set(unsigned int a, struct set set );


unsigned int closest_in_set1_to_set2(struct set set1, struct set set2);


unsigned int closest_movement_to_other_player(struct game_t game);

#endif