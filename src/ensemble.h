#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"

struct ensemble;

void positions_init(struct ensemble* pi);

void ajout_position(struct ensemble* p , unsigned int place );

void black_list(struct ensemble* pw, struct world_t* w);

void white_list(struct ensemble* pb, struct world_t* w);

int place_visited (struct ensemble* p, unsigned int place );

void concatener_ensembles(struct ensemble* a, struct ensemble* b );

#endif 
