#ifndef __MOVEMENTS_H__
#define __MOVEMENTS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"

/* Fonction qui retourne l'ensemble des déplacements simple possible */
void deplacements_simple(struct world_t* w , unsigned int idx , struct ensemble* ds);

/* Fonction qui retourne l'ensemble des sauts simples */
void saut_simple(struct world_t* w , unsigned int idx , struct ensemble* ss);

/* Fonction qui retourne l'ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) */
void saut_multiple(struct world_t* w , unsigned int idx , struct ensemble* sm);

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
struct ensemble* mvts_disponibles (struct world_t* w, unsigned int idx, struct ensemble* md );

#endif //__MOVEMENTS_H__