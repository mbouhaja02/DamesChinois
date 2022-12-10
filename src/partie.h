#ifndef __PARTIE_H__
#define __PARTIE_H__


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "victoire.h"

static struct game_t {
    enum color_t current_player;
    unsigned int tour ;
    struct world_t* w;
    unsigned int seed;
    unsigned int position; 
    enum victoire_t victoire;
} game ;

enum color_t get_random_player();

enum color_t next_player(enum color_t current_player);

unsigned int choose_random_piece_belonging_to(struct game_t* game);

unsigned int choose_random_move_for_piece(struct game_t* game);

void move_piece(struct game_t* game, unsigned int dst);

#endif // __PARTIE_H__