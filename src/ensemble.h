#ifndef __ENSEMBLE_H_
#define __ENSEMBLE_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"


struct ensemble {
    unsigned int taille;
    unsigned int positions[WORLD_SIZE];
    
};


void positions_init(struct ensemble* pi);

void ajout_position(struct ensemble* p , unsigned int place );

void black_list(struct ensemble* pw, struct world_t* w);

void white_list(struct ensemble* pb, struct world_t* w);

int place_visited (struct ensemble* p, unsigned int place );

void concatener_ensembles(struct ensemble* a, struct ensemble* b );

#endif 
