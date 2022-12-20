
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

static struct prison_t prison;

struct prison_t* init_prison(){

    prison.len_white = 0;
    prison.len_black = 0;

    
    for(int i = 0; i < WORLD_SIZE; i++){
        prison.cells[i].i = UINT_MAX;
        prison.cells[i].c = NO_COLOR;
        prison.cells[i].s = NO_SORT;
    }
    return &prison;
}

void add_prisoner(struct game_t game, unsigned int idx){

    if(world_get(game.w, idx) == 1){
        game.prison->len_black = game.prison->len_black + 1;
        game.prison->cells[game.prison->len_black].c = world_get(game.w, idx);
        game.prison->cells[game.prison->len_black].s = world_get_sort(game.w, idx);
        game.prison->cells[game.prison->len_black].i = idx;

    }
    else if (world_get(game.w, idx) == 2) {
        game.prison->len_white = game.prison->len_white + 1;
        game.prison->cells[WORLD_SIZE - game.prison->len_white + 1].c = world_get(game.w, idx);
        game.prison->cells[WORLD_SIZE - game.prison->len_white + 1].s = world_get_sort(game.w, idx);
        game.prison->cells[WORLD_SIZE - game.prison->len_white + 1].i = idx;

    }
}
void escape_attempts(struct game_t game){
    srand(time(NULL));
    int r = rand()%2;
    for(unsigned int i = 0; i < WORLD_SIZE; i++){

        if (world_get_sort(game.w, game.prison->cells[i].i) == NO_SORT && r == 1){
            success_escape(game, game.prison->cells[i]);
            printf("\n 3#2 \n");
        }
    }
}

void success_escape(struct game_t game, struct prisoner_t prisoner){
    struct prisoner_t prisoner2;
    world_set(game.w, prisoner.i, prisoner.c);
    world_set_sort(game.w, prisoner.i, prisoner.s);

    if(world_get(game.w, prisoner.i) == 1){
        prisoner2 = game.prison->cells[game.prison->len_black];
        prisoner = game.prison->cells[game.prison->len_black];
        world_set(game.w, prisoner2.i, NO_COLOR);
        world_set_sort(game.w, prisoner2.i, NO_SORT);
        prisoner2.i = UINT_MAX;
        game.prison->len_black = game.prison->len_black - 1;
    }
    if(world_get(game.w, prisoner.i) == 2){
        prisoner2 = game.prison->cells[WORLD_SIZE - game.prison->len_white + 1];
        prisoner = game.prison->cells[WORLD_SIZE - game.prison->len_white + 1];
        world_set(game.w, prisoner2.i, NO_COLOR);
        world_set_sort(game.w, prisoner2.i, NO_SORT);
        prisoner2.i = UINT_MAX;
        game.prison->len_white = game.prison->len_white - 1;
    }
    
}