#ifndef __PRISON_H__
#define __PRISON_H__



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "movements.h"
#include "prison.h"
#include "game.h"


struct prisoner_t{
  enum color_t c;
  enum sort_t s;
  unsigned int i;
};

struct jail_t{
  unsigned int len_white;
  unsigned int len_black;
  struct prisoner_t cells_white[WORLD_SIZE];
  struct prisoner_t cells_black[WORLD_SIZE];
};

struct jail_t* init_prison();

void add_prisoner(struct jail_t* prison, struct game_t game, unsigned int idx);

void escape_attempts(struct game_t game);

void success_escape(struct game_t game, struct prisoner_t prisoner);


#endif //__PRISON_H__