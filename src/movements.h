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
void simple_moves( struct game_t game, struct ensemble* sm);

/*Fonction qui ajoute à un ensemble les differents capture simple disponibles pour un pawn*/
void simple_moves_capture( struct game_t game, struct ensemble* smc);



/* Fonction qui ajoute à un ensemble les sauts simples possibles pour un pawn*/
void simple_jumps(struct game_t game , struct ensemble* sj);

/*Fonction qui ajoute à un ensemble les differents capture saut simple disponibles pour un pawn*/
void simple_jumps_capture(struct game_t game , struct ensemble* sjc);



/* Fonction qui ajoute à un ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) pour un pawn*/
void multiple_jumps(struct game_t game , struct ensemble* mj);

/*Fonction qui ajoute les differents capture saut simple disponibles pour un pawn*/
void multiple_jumps_capture(struct game_t game , struct ensemble* mjc  );



/* Fonction qui retourne l'ensemble des mouvements possibles pour l'éléphant*/
void semi_diagonal_jumps(struct game_t game, struct ensemble* sdj);

/* Fonction qui rajoute à un ensemble les differents captures disponibles pour un éléphant*/
void semi_diagonal_jumps_capture(struct game_t game, struct ensemble* sdjc);



/* Fonction qui retourne l'ensemble des mouvements possibles pour la tour*/
void cardinal_translations(struct game_t game, struct ensemble* ct);

/*Fonction qui ajoute à un ensemble les differents captures disponibles pour une tour*/
void cardinal_translations_capture(struct game_t game, struct ensemble* ctc);



/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
void available_movements(struct game_t game, struct ensemble* am);

/*Tout mouvement de la pièce qui se termine sur une case 
  contenant une pièce d'une couleur différente capture 
          la pièce en question.*/
void available_captures(struct game_t game, struct ensemble* ac);


#endif //__MOVEMENTS_H__