#ifndef __ENSEMBLE_H_
#define __ENSEMBLE_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ensemble.h"
#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "movements.h"

struct ensemble{
    unsigned int taille;
    unsigned int positions[WORLD_SIZE];
    
};

void positions_init(struct ensemble* pi);

/* On ajoute une positions place à un ensemble p */ 
void ajout_position(struct ensemble* p , unsigned int place );

void black_list(struct ensemble* pw, struct world_t* w);

void white_list(struct ensemble* pb, struct world_t* w);

int place_visited (struct ensemble* p, unsigned int place );

int element_commun(struct ensemble* ens, struct ensemble* ens2);

int egalite_de_deux_ensembles(struct ensemble a, struct ensemble b);


#endif 
