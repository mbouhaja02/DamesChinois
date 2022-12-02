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

enum color_t get_random_player();

enum color_t next_player(enum color_t current_player);

unsigned int choose_random_piece_belonging_to(struct world_t* w , enum color_t current_player);

unsigned int choose_random_move_for_piece(struct world_t* w, unsigned int p);

struct world_t* move_piece(struct world_t* w,unsigned int m, unsigned int p , enum color_t joueur);

#endif // __PARTIE_H__