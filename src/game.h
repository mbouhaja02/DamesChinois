#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "game.h"
#include "prison.h"


struct game_t {
    enum color_t current_player;
    unsigned int tour;
    struct world_t* w;
    struct prison_t* prison;
    unsigned int seed;
    unsigned int position;
    enum victoire_t victoire;

};

/* Return a random color of a player (white or black)*/
enum color_t get_random_player();

/*Return the color of the next player knowing the color of the previous player*/
enum color_t next_player(enum color_t current_player);

/*Choose a random piece belonging to one of the players defined in game.position*/
void choose_random_piece_belonging_to(struct game_t* game);

/*Return a random move (index)*/
unsigned int choose_random_move_for_piece(struct game_t game);

/*move a peice knowing the next index of our piece (game.position)*/
void move_piece(struct game_t game, unsigned int dst);

/*Retrun a game which has been initialized*/
struct game_t game_initializer();

//chooses the relation mode randomly
void choose_random_relation(struct game_t *game);

void draw_legend();



#endif // __GAME_H__