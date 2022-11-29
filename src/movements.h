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
struct ensemble deplacements_simple(struct world_t w , unsigned char idx , struct ensemble* ds);

/* Fonction qui retourne l'ensemble des sauts simples */
struct ensemble saut_simple(struct world_t w , unsigned char idx , struct ensemble* ss);

/* Fonction qui retourne l'ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) */
struct ensemble saut_multiple(struct world_t w , unsigned char idx , struct ensemble* sm);

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
struct ensemble mvts_disponibles (struct world_t w, unsigned char idx, struct ensemble* md );

#endif //__MOVEMENTS_H__