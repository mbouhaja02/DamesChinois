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

int Victoire_Simple(struct world_t w , unsigned int place , enum color_t joueur , unsigned int tours ) ;

int Victoire_complexe(struct world_t* w , unsigned int tours , enum color_t joueur , struct world_t* wt);


#endif