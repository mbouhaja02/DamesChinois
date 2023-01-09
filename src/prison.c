
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "movements.h"
#include "game.h"
#include "prison.h"

static struct jail_t prison;

struct jail_t* init_prison(){

    prison.len_white = 0;
    prison.len_black = 0;

    for(int i = 0; i < WORLD_SIZE; i++){
        prison.cells_white[i].i = UINT_MAX;
        prison.cells_white[i].c = NO_COLOR;
        prison.cells_white[i].s = NO_SORT;
        prison.cells_black[i].i = UINT_MAX;
        prison.cells_black[i].c = NO_COLOR;
        prison.cells_black[i].s = NO_SORT;
    }
    return &prison;
}

void add_prisoner(struct jail_t* prison,struct game_t game, unsigned int idx){

    if(world_get(game.w, idx) == 1){
        prison->cells_black[prison->len_black].c = world_get(game.w, idx);
        prison->cells_black[prison->len_black].s = world_get_sort(game.w, idx);
        prison->cells_black[prison->len_black].i = idx;
        prison->len_black = prison->len_black + 1;

    }
    else if (world_get(game.w, idx) == 2) {
        prison->cells_white[prison->len_white].c = world_get(game.w, idx);
        prison->cells_white[prison->len_white].s = world_get_sort(game.w, idx);
        prison->cells_white[prison->len_white].i = idx;
        prison->len_white = prison->len_white + 1;

    }
}

void escape_attempts(struct game_t game){
    srand(time(NULL));
    int r = rand()%2;

    if(world_get(game.w, game.position) == 1){
        for(unsigned int i = 0; i < game.jail->len_white; i++){
            if(r == 1 && world_get_sort(game.w, game.jail->cells_white[i].i) == NO_SORT){
                success_escape(game, game.jail->cells_white[i]);
            }
        }
    }

    if(world_get(game.w, game.position) == 2){
        for(unsigned int i = 0; i < game.jail->len_black; i++){
            if(r == 1 && world_get_sort(game.w, game.jail->cells_black[i].i) == NO_SORT){
                success_escape(game, game.jail->cells_black[i]);
            }
        }
    }
    
}

void success_escape(struct game_t game, struct prisoner_t prisoner){
    struct prisoner_t prisoner2;
    world_set(game.w, prisoner.i, prisoner.c);
    world_set_sort(game.w, prisoner.i, prisoner.s);

    if(prisoner.c == 1){
        prisoner2 = game.jail->cells_black[game.jail->len_black];
        prisoner = game.jail->cells_black[game.jail->len_black];
        world_set(game.w, prisoner2.i, NO_COLOR);
        world_set_sort(game.w, prisoner2.i, NO_SORT);
        prisoner2.i = UINT_MAX;
        game.jail->len_black = game.jail->len_black - 1;
    }
    if(prisoner.c == 2){
        prisoner2 = game.jail->cells_white[game.jail->len_white];
        prisoner = game.jail->cells_white[game.jail->len_white];
        world_set(game.w, prisoner2.i, NO_COLOR);
        world_set_sort(game.w, prisoner2.i, NO_SORT);
        prisoner2.i = UINT_MAX;
        game.jail->len_white = game.jail->len_white - 1;
    }
    
}