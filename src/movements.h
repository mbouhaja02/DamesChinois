#ifndef __MOVEMENTS_H__
#define __MOVEMENTS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "game.h"



/* Fonction qui retourne l'ensemble des déplacements simple possible */
void deplacements_simple( struct game_t game, struct ensemble* ds);

/* Fonction qui retourne l'ensemble des sauts simples */
void saut_simple(struct game_t game , struct ensemble* ss);

/* Fonction qui retourne l'ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) */
void saut_multiple(struct game_t game , struct ensemble* sm);

/* Fonction qui retourne l'ensemble des mouvements possibles pour l'éléphant*/
void saut_semi_diagonal(struct game_t game, struct ensemble* ssd);

/* Fonction qui retourne l'ensemble des mouvements possibles pour la tour*/
void translation_cardinal(struct game_t game, struct ensemble* tc);

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
void mvts_disponibles (struct game_t game, struct ensemble* md);


void capture_deplacements_simple( struct game_t game, struct ensemble* cds );

void capture_saut_simple(struct game_t game , struct ensemble* css);

void capture_saut_multiple(struct game_t game , struct ensemble* csm  );


/*Tout mouvement de la pièce qui se termine sur une case 
  contenant une pièce d'une couleur différente capture 
          la pièce en question.*/
void capture_dispo(struct game_t game, struct ensemble* cd);

#endif //__MOVEMENTS_H__