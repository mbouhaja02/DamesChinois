#ifndef __MOVEMENTS_H__
#define __MOVEMENTS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "game.h"
#include "prison.h"



/* Fonction qui ajoute à un ensemble les déplacements simple possible pour un pawn*/
void deplacements_simple( struct game_t game, struct ensemble* ds);

/* Fonction qui ajoute à un ensemble les sauts simples possibles pour un pawn*/
void saut_simple(struct game_t game , struct ensemble* ss);

/* Fonction qui ajoute à un ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) pour un pawn*/
void saut_multiple(struct game_t game , struct ensemble* sm);

/* Fonction qui retourne l'ensemble des mouvements possibles pour l'éléphant*/
void saut_semi_diagonal(struct game_t game, struct ensemble* ssd);

/* Fonction qui retourne l'ensemble des mouvements possibles pour la tour*/
void translation_cardinal(struct game_t game, struct ensemble* tc);


/* Fonction qui rajoute à un ensemble les differents captures disponibles pour un éléphant*/
void capture_saut_semi_diagonal(struct game_t game, struct ensemble* ssd);


/*Fonction qui ajoute à un ensemble les differents captures disponibles pour une tour*/
void capture_translation_cardinal(struct game_t game, struct ensemble* tc);

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
void mvts_disponibles (struct game_t game, struct ensemble* md);


/*Fonction qui ajoute à un ensemble les differents capture simple disponibles pour un pawn*/
void capture_deplacements_simple( struct game_t game, struct ensemble* cds );


/*Fonction qui ajoute à un ensemble les differents capture saut simple disponibles pour un pawn*/
void capture_saut_simple(struct game_t game , struct ensemble* css);

/*Fonction qui ajoute les differents capture saut simple disponibles pour un pawn*/
void capture_saut_multiple(struct game_t game , struct ensemble* csm  );


/*Tout mouvement de la pièce qui se termine sur une case 
  contenant une pièce d'une couleur différente capture 
          la pièce en question.*/
void capture_dispo(struct game_t game, struct ensemble* cd);
#endif //__MOVEMENTS_H__